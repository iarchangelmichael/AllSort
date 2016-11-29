
class SortStack{
public:
	// Data
	unsigned int *data;

	// Size
	unsigned int sz, *pos, *fpos, *lpos;

	SortStack(){
		data = 0;
		Clean();
	}

	void Clean(){
		free(data);
		data = 0;
		sz = 0;
	}

	~SortStack(){
		Clean();
	}

//inline unsigned int& operator[](unsigned int i){return data[i];}
//inline int& fpos(unsigned int i){return fpos[i];}
//inline int& lpos(unsigned int i){return lpos[i];}

	void New(unsigned int size, unsigned int base, unsigned int basesize){
		free(data);
		sz = size;
		
		data = (unsigned int*)malloc((sz + base * 2) * sizeof(int) + sz * basesize);
		pos = (unsigned int*)((char*)data + sz * basesize);
		fpos = pos + sz;
		lpos = fpos + base;
		memset(fpos, 255, base * 2 * sizeof(int));
		
		return ;
	}
};

inline unsigned int mfsbs(unsigned int val){
	unsigned int ret=0; while(val){ val/=2; ret++; } return ret;
}

void myfastsort8(unsigned int size, unsigned int *arr){
	unsigned int bits=8, bit, k, p, j;
	SortStack st; st.New(size, 256, sizeof(int));

	for(unsigned int i=0; i<sizeof(int)*8; i+=bits){
		memset(st.data, 0, size*sizeof(int)+size*sizeof(int)); memset(st.fpos, 255, 256*2*sizeof(int));
		bit=(256-1)<<i;
		for(j=0; j<size; j++) {
			k=arr[j]&bit; k=k>>i;
			if(st.fpos[k]==-1){ st.fpos[k]=j; } else { st.pos[st.lpos[k]]=j; }
			st.data[j]=arr[j]; st.lpos[k]=j;
		}k=0;

		for(j=0; j<256; j++){
			p=st.fpos[j]; 
			if(p!=-1) while(1){
				arr[k]=st.data[p];
				p=st.pos[p];
				k++;
				if(!p)
					break;
			}
		}
	} return ;
}


template<class T>
class ASortStackPoi{
public:
	ASortStackPoi *_n;
	T *el;
};

template<class T>
class ASortStackBase{
public:
	ASortStackPoi<T> *_a, *_e;		
};

template<class T>
class ASortStack{
	// Data & size & elements
	unsigned char *data;
	unsigned int sz;
	unsigned int els;

	// Base
	unsigned int base;

public:
	ASortStack(){
		data = 0;
		Clean();
	}

	void Reserv(unsigned int base, unsigned int els){
		Clean();

		data = (unsigned char*)malloc(2 * base * sizeof(ASortStackBase<T>) + 2 * els * sizeof(ASortStackPoi<T>));
		this->base = base;
		this->els = els;

		return ;
	}

	ASortStackBase<T>* GetBase(bool id = 0){
		if(!data)
			return 0;

		if(!id)
			return (ASortStackBase<T>*)data;
		else
			return (ASortStackBase<T>*)(data + base * sizeof(ASortStackBase<T>));
	}

	ASortStackPoi<T>* GetPoi(bool id = 0){
		if(!data)
			return 0;

		if(!id)
			return (ASortStackPoi<T>*)(data + 2 * base * sizeof(ASortStackBase<T>));
		else
			return (ASortStackPoi<T>*)(data + 2 * base * sizeof(ASortStackBase<T>) + els * sizeof(ASortStackPoi<T>));
	}

	void CleanBase(ASortStackBase<T> *b){
		if(b)
			memset(b, 0, base * sizeof(ASortStackBase<T>));
		return ;
	}

	void Clean(){
		free(data);
		data = 0;
		base = 0;
		sz = 0;		
	}

	~ASortStack(){
		Clean();
	}


};

// All sort
class ASort{

	
public:

	// Sort array
	template<class T>
	void RadixSort(T *arr, unsigned int sz){  ///  NOT WORK ///
		const unsigned int tsz = sizeof(T);
		ASortStack<T> stack;
		ASortStackBase<T> *baseo, *baset, *base;
		ASortStackPoi<T> *poio, *poit, *poi;

		stack.Reserv(256, sz);
		baseo = stack.GetBase(0);
		baset = stack.GetBase(1);
		poio = stack.GetPoi(0);
		poit = stack.GetPoi(1);

		stack.CleanBase(baseo);
		poi = poio;

		// First
		for(unsigned int e = 0; e < sz; e ++){
			if(baseo[arr[e] & 255]._a)
				baseo[arr[e] & 255]._e->_n = poi;
			else
				baseo[arr[e] & 255]._a = poi;			

			baseo[arr[e] & 255]._e = poi;
			poi->el = &arr[e];
			poi ++;
		}

		for(unsigned int i = 1; i < tsz; i++){
			

			// Reval
			poi = poio;
			poio = poit;
			poit = poi;

			base = baseo;
			baseo = baset;
			baset = base;
		}

		return ;
	}

	// swap
	template<class T>
	void swap(T& left, T& right){
		T tmp = move(left);
		left = move(right);
		right = move(tmp);
	}

	template<class T>
	struct remove_reference{
		typedef T type;
	};

	template<class T> inline
	typename remove_reference<T>::type&&
	move(T& val){
		return ((typename remove_reference<T>::type&&)val);
	}

	template<class T>
	void BubbleSort(T *arr, unsigned int sz){
		T tmp;
		int sorted = 1;

		while(sorted){
			sorted = 0;

			for(unsigned int i = 0; i < sz - 1; i ++){
				if(arr[i] > arr[i + 1]){

					//using std::swap;
					swap(arr[i], arr[i+1]);

					// OR
					//memcpy(&tmp, &arr[i], sizeof(T));
					//memcpy(&arr[i], &arr[i + 1], sizeof(T));
					//memcpy(&arr[i + 1], &tmp, sizeof(T));

					sorted = 1;
				}
			}
		}

		memset(&tmp, 0, sizeof(T));
	}

	template<class T>
	void InversionSort(T *arr, unsigned int sz){
		T tmp;

		for(unsigned int i = 0; i < sz - 1; i ++){
			for(unsigned int j = i + 1; j < sz; j ++){
				if(arr[i] > arr[j]){
					//using std::swap;
					swap(arr[i], arr[j]);

					// OR
					//memcpy(&tmp, &arr[i], sizeof(T));
					//memcpy(&arr[i], &arr[j], sizeof(T));
					//memcpy(&arr[j], &tmp, sizeof(T));
				}
			}
		}

		memset(&tmp, 0, sizeof(T));
	}

	template<class T>
	void InsertionSort(T *arr, unsigned int sz){
		T tmp;

		for(unsigned int i = 0; i < sz; i ++){
			memcpy(&tmp, &arr[i], sizeof(T));

			int j = i - 1;

			while(j >= 0 && tmp < arr[j]){
				memcpy(&arr[j + 1], &arr[j], sizeof(T));
				j --;
			}

			memcpy(&arr[j + 1], &tmp, sizeof(T));
		}

		memset(&tmp, 0, sizeof(T));
	}

	template<class T>
	void BinaryInsertionSort(T *arr, unsigned int sz){
		unsigned int count, step;
		T *first, *it, tmp;

		for(unsigned int i = 0; i < sz; i ++){
			memcpy(&tmp, &arr[i], sizeof(T));

			count = i;
			first = arr;

			while(count){
				step = count / 2;
				it = first + step;

				if(*it < arr[i]){
					first = ++it;
					count -= step + 1;
				} else
					count = step;
			}
			memcpy(first + 1, first, (i - (first - arr)) * sizeof(T));
			memcpy(first, &tmp, sizeof(T));
		}

		memset(&tmp, 0, sizeof(T));
	}


	template<class T>
	void ShellSort(T *arr, unsigned int sz){
		unsigned int c, i, g, j;
		
		g = sz / 2;
		sz --;

		while(g){
			i = g;
			while(i <= sz){
				j = i - g;
				c = 1;
				
				while(c){
					if(arr[j] <= arr[j + g])
						c = 0;
					else
						swap(arr[j], arr[j + g]);

					if(!j)
						break;

					j --;
				}   
				i ++;
			}
			g /= 2;
		}

		return ;
	}

	template<class T>
	void HeapSort(T *arr, unsigned int sz){
		unsigned int i, k, t;

		i = 2;
		while(i <= sz){
			t = i;
			while(t != 1){
				k = t / 2;
				if(arr[k - 1] >= arr[t - 1])
					t = 1;
				else{
					swap(arr[k - 1], arr[t - 1]);
					t = k;
				}
			}
			i ++;
		}
		
		i = sz - 1;
		while(i >= 1){
			swap(arr[i], arr[0]);
			t = 1;
			while(t != 0){
				k = 2 * t;
				if(k > i)
					t = 0;
				else{				
					if(k < i)
						if(arr[k] > arr[k - 1])
							k ++;

					if(arr[t - 1] >= arr[k - 1])
						t = 0;
					else{
						swap(arr[k - 1], arr[t - 1]);
						t = k;
					}
				}
			}
			i --;
		}

		return ;
	}

	template<class T>
	void QuickSort(T *arr, unsigned int sz){
		return QuickSort(arr, 0, (int)sz);
	}

	template<class T>
	void QuickSort(T *arr, int l, int r){
		int i, j;
		T p;

		i = l;

		while(i < r){
			i = l;
			j = r;
			p = arr[(l + r) >> 1];

			while(i < j){
				while(arr[i] < p)
					i ++;

				while(arr[j] > p)
					j --;

				  if(i <= j){
						swap(arr[i], arr[j]);
						i ++;
						j --;
				  }
			}

			if(l < j)
			  QuickSort(arr, l, j);
			l = i;
		}

		return ;
	}

	template<class T>
	void MergeSort(T *arr, unsigned int sz){
		T * tarr = new T[sz];

		if(arr != MergeSort(arr, tarr, 0, sz))
			memcpy(arr, tarr, sz * sizeof(T));
		
		//merge_sort(arr, tarr, 0, sz);

		//memcpy(arr, tarr, sz * sizeof(T));

		//if(!TestArray(arr, sz))
		//	int ert = 4567;

		delete [] tarr;

		return ;
	}

	template<class T>
	bool TestArray(T *arr, unsigned int sz){
		for(unsigned int i = 0; i < sz - 1; i ++){
			if(arr[i] > arr[i + 1])
				return 0;
		}
		
		return 1;
	}

	template<class T>
	T* MergeSort(T *arr, T *tarr, unsigned int left, unsigned int right){
		if(left == right){
			tarr[left] = move(arr[left]);
			return tarr;
		}

		unsigned int center = (unsigned int)((left + right) * 0.5);

		T *larr = MergeSort(arr, tarr, left, center);
		T *rarr = MergeSort(arr, tarr, center + 1, right);
		T* res = larr == arr ? tarr : arr;

		unsigned int pleft = left, pright = center + 1;


		//for(unsigned int i = left; i <= right; i ++){
		unsigned int i = left;

		while(pleft <= center && pright <= right){
			if(larr[pleft] < rarr[pright]){
				res[i++] = move(larr[pleft]);
				pleft ++;
			} else {
				res[i++] = move(rarr[pright]);
				pright ++;
			}
		}

		if(pleft > center){
			if(pright <= right)				
				//memcpy(&res[i], &rarr[pright], (right - pright + 1) * sizeof(T));
				std::copy(std::make_move_iterator(&rarr[pright]), std::make_move_iterator(&rarr[right + 1]), &res[i]);
				
					std::copy(&rarr[pright], &rarr[right + 1], &res[i]);
				//break;
		} else if(pright > right){
			if(pleft <= center)
				//memcpy(&res[i], &larr[pleft], (center - pleft + 1) * sizeof(T));
				std::copy(std::make_move_iterator(&larr[pleft]), std::make_move_iterator(&larr[center + 1]), &res[i]);

				//std::copy(&larr[pleft], &larr[center + 1], &res[i]);
				//break;
			}
		//}

		//if(!TestArray(res + left, right - left + 1))
		//	int rt = 657;

		return res;
	}

};


