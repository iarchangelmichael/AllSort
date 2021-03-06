#ifdef NOUSEIT
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

#endif

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

	void Reserv(unsigned int size){
		Clean();

		data = (unsigned char*)malloc(size);
		this->base = 0;
		this->els = 0;

		return ;
	}

	unsigned char* GetData(){
		return data;
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
		els = 0;
	}

	~ASortStack(){
		Clean();
	}

};



// All sort
class ASort{
	
public:

	// swap
	template<class T>
	static void swap(T& left, T& right){
		T tmp = move(left);
		left = move(right);
		right = move(tmp);
	}

	template<class T>
	struct remove_reference{
		typedef T type;
	};

	template<class T> inline
	static typename remove_reference<T>::type&&
	move(T& val){
		return ((typename remove_reference<T>::type&&)val);
	}

	// Sorts
	template<class T>
	static void BubbleSort(T *arr, unsigned int sz){
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
	static void InversionSort(T *arr, unsigned int sz){
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
	static void InsertionSort(T *arr, unsigned int sz){
		T tmp;

		for(unsigned int i = 0; i < sz; i ++){
			//memcpy(&tmp, &arr[i], sizeof(T));
			tmp = move(arr[i]);

			int j = i - 1;

			while(j >= 0 && tmp < arr[j]){
				//memcpy(&arr[j + 1], &arr[j], sizeof(T));
				arr[j + 1] = move(arr[j]);
				j --;
			}

			//memcpy(&arr[j + 1], &tmp, sizeof(T));
			arr[j + 1] = move(tmp);
		}

		//memset(&tmp, 0, sizeof(T));
	}

	template<class T>
	static void BinaryInsertionSort(T *arr, unsigned int sz){
		unsigned int count, step;
		T *first, *it, tmp;

		for(unsigned int i = 0; i < sz; i ++){
			//memcpy(&tmp, &arr[i], sizeof(T));
			tmp = move(arr[i]);

			count = i;
			first = arr;

			while(count){
				step = count / 2;
				it = first + step;

				if(*it < tmp){
					first = ++it;
					count -= step + 1;
				} else
					count = step;
			}

			//if(first != &arr[i])
				//memcpy(first + 1, first, (i - (first - arr)) * sizeof(T));
			//
			std::move_backward(first, &arr[i], &arr[i + 1]);
				//std::move_backward(std::make_move_iterator(first), std::make_move_iterator(&arr[i]), (first + 1));
				//std::move(first, &arr[i], first + 1);

			//T *f = first, *t = arr + i;
			//while(t > f){
			//	*t = move(*(t - 1));
			//	t --;
			//}

			//memcpy(first, &tmp, sizeof(T));
			*first = move(tmp);
		}

		//memset(&tmp, 0, sizeof(T));
		return ;
	}


	template<class T>
	static void ShellSort(T *arr, unsigned int sz){
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
	static void HeapSort(T *arr, unsigned int sz){
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
	static void QuickSort(T *arr, unsigned int sz){
		return QuickSort(arr, 0, (int)sz - 1);
	}

	template<class T>
	static void QuickSort(T *arr, int l, int r){
		int i, j, c;
		T p;

		i = l;
		j = r;

		while(i < r){
			i = l;
			j = r;
			p = arr[c = (l + r) >> 1];

			while(i < j){
				while(i < r && arr[i] < p)
					i ++;

				while(j > l && arr[j] > p)
					j --;

					if(i <= j){
						swap(arr[i], arr[j]);
						//memcpy(&tmp, &arr[i], sizeof(T));
						//memcpy(&arr[i], &arr[j], sizeof(T));
						//memcpy(&arr[j], &tmp, sizeof(T));
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
	static void MergeSort(T *arr, unsigned int sz){
		T * tarr = new T[sz];

		if(arr != MergeSort(arr, tarr, 0, sz - 1))
			//memcpy(arr, tarr, sz * sizeof(T));
			std::move(std::make_move_iterator(tarr), std::make_move_iterator(tarr + sz), arr);
		
		delete [] tarr;

		return ;
	}

	template<class T>
	static bool TestArray(T *arr, unsigned int sz){
		for(unsigned int i = 0; i < sz - 1; i ++){
			if(arr[i] > arr[i + 1])
				return 0;
		}
		
		return 1;
	}

	template<class T>
	static T* MergeSort(T *arr, T *tarr, unsigned int left, unsigned int right){
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
				
				//std::copy(&rarr[pright], &rarr[right + 1], &res[i]);
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


	//  My realization Radix sort
	template<class T>
	class RadixSortStack{
	public:
		T *data;
		unsigned int *pos, *fpos, *lpos;
		unsigned int sz;

		// T data[sz] - temp data
		// uint pos - new element position
		// uint fpos - uint[base].first
		// uint lpos - uint[base].last

		RadixSortStack(){
			memset(this, 0, sizeof(RadixSortStack));
		}

		~RadixSortStack(){
			free(data);
			data = 0;
		}

		void New(unsigned int size, unsigned int base){
			free(data);
			
			sz = size;
			data = (T*)malloc(sz * sizeof(T) + sz * sizeof(unsigned int) + 2 * base * sizeof(unsigned int));
			
			pos = (unsigned int*)(data + sz);
			fpos = pos + sz;
			lpos = fpos + base;
			
			return ;
		}
	};

	unsigned int RadixSortBits(unsigned int val){
		unsigned int ret = 0;
		while(val){
			val /= 2;
			ret ++;
		}
		return ret;
	}

	// Radix sort. move() count 2 * size per byte(sizeof(T)). 
	template<class T>
	void RadixSort(T *arr, unsigned int size, unsigned int base = 256){
		unsigned int bits = RadixSortBits(base - 1), k, p, j;
		RadixSortStack<T> st;
		st.New(size, base);

		// Only 256
		if(base != 256)
			return ;

		for(unsigned int i = 0; i < sizeof(T); i ++){
			memset(st.data, 0, size * sizeof(T));
			memset(st.pos, 0, size * sizeof(int));
			memset(st.fpos, 255, 2 * base * sizeof(int));

			//bit = (base - 1) << i;
			for(j = 0; j < size; j ++){
				k = (arr[j] >> (8 * i)) & 255;
				//k = k >> i;

				if(st.fpos[k] == -1){
					st.fpos[k] = j;
				} else {
					st.pos[st.lpos[k]] = j;
				}
				st.data[j] = move(arr[j]);
				st.lpos[k] = j;
			}
			k = 0;

			for(j = 0; j < base; j ++){
				p = st.fpos[j];
				if(p != -1) while(1){
					arr[k] = move(st.data[p]);
					p = st.pos[p];
					k ++;
				
					if(!p)
						break;
				}
			}
		}
		return ;
	}

	// Radix sort + Pointer. move() count 1 * size per byte(sizeof(T)).
	template<class T>
	static void RadixPoiSort(T *arr, unsigned int sz){
		const unsigned int tsz = sizeof(T);
		ASortStackBase<T> *base;
		ASortStackPoi<T> *poif, *poi;

		T *arrt = /*(T*) malloc(sz * sizeof(T));*/ new T[sz]; //(T*) data;//stack.GetData();
		base = (ASortStackBase<T>*) malloc(256 * sizeof(ASortStackBase<T>)); //new ASortStackBase<T>[256]; //stack.GetBase(0);
		poif = (ASortStackPoi<T>*) malloc(sz * sizeof(ASortStackPoi<T>));// ASortStackPoi<T>[sz]; //stack.GetPoi(0);

		//memset(arrt, 0, sz * sizeof(T));


		for(unsigned int b = 0; b < sizeof(T); b ++){
			memset(base, 0, 256 * sizeof(ASortStackBase<T>));
			poi = poif;

			for(unsigned int e = 0; e < sz; e ++){
				unsigned int c = (arr[e] >> (8 * b)) & 255;

				if(base[c]._a)
					base[c]._e->_n = poi;
				else
					base[c]._a = poi;			

				base[c]._e = poi;
				poi->el = &arr[e];
				poi ++;
			}

			unsigned int idx = 0;

			for(unsigned int i = 0; i < 256; i++){	
				poi = base[i]._a;
				while(poi){
					arrt[idx] = move(*poi->el);
					idx ++;

					if(poi == base[i]._e)
						break;
					else
						poi = poi->_n;
				}
			}

			swap(arr, arrt);
		}

		delete[] arrt;
		//free(arrt); 

		free(base); //delete[] base;
		free(poif); //delete[] poif;

		return ;
	}



	// Radix sort + Pointers. move() count ... wait.  //move() count 1 * size per byte(sizeof(T)).
	template<class T>
	static void RadixPoisSort(T *arr, unsigned int sz){
		const unsigned int tsz = sizeof(T);
		ASortStackBase<T> *base, *baset;
		ASortStackPoi<T> *poif, *poit, *poi, *p;

		//for(unsigned int i = 0; i < sz; i ++)
		//	printf("%d, ", arr[i]);

		T *tarr = /*(T*) malloc(sz * sizeof(T));*/ new T[sz]; //(T*) data;//stack.GetData();
		base = (ASortStackBase<T>*) malloc(256 * sizeof(ASortStackBase<T>)); //new ASortStackBase<T>[256]; //stack.GetBase(0);
		poif = (ASortStackPoi<T>*) malloc(sz * sizeof(ASortStackPoi<T>));// ASortStackPoi<T>[sz]; //stack.GetPoi(0);

		baset = (ASortStackBase<T>*) malloc(256 * sizeof(ASortStackBase<T>)); //new ASortStackBase<T>[256]; //stack.GetBase(0);
		poit = (ASortStackPoi<T>*) malloc(sz * sizeof(ASortStackPoi<T>));// ASortStackPoi<T>[sz]; //stack.GetPoi(0);
		//memset(arrt, 0, sz * sizeof(T));

		unsigned int idx = 0;

		//for(unsigned int b = 0; b < sizeof(T); b ++){
		
		// First
		memset(base, 0, 256 * sizeof(ASortStackBase<T>));
		poi = poif;
			
		for(unsigned int e = 0; e < sz; e ++){
			unsigned int c = arr[e] & 255;

			if(base[c]._a)
				base[c]._e->_n = poi;
			else
				base[c]._a = poi;			

			base[c]._e = poi;
			poi->el = &arr[e];
			poi ++;
		}
		//}

		for(unsigned int b = 1; b < sizeof(T); b ++){
			memset(baset, 0, 256 * sizeof(ASortStackBase<T>));

			idx = 0;
			poi = poit;

			for(unsigned int i = 0; i < 256; i++){	
				p = base[i]._a;
				while(p){
					unsigned int c = (*p->el >> (8 * b)) & 255;

					if(baset[c]._a)
						baset[c]._e->_n = poi;
					else
						baset[c]._a = poi;			

					baset[c]._e = poi;
					poi->el = p->el;
					poi ++;

					//arrt[idx] = move(*poi->el);
					//idx ++;

					if(p == base[i]._e)
						break;
					else
						p = p->_n;
				}
			}

			swap(base, baset);
			swap(poif, poit);
			//swap(arr, arrt);
		}

		for(unsigned int i = 0; i < 256; i++){	
			poi = base[i]._a;
			while(poi){
				tarr[idx] = move(*poi->el);
				idx ++;

				if(poi == base[i]._e)
					break;
				else
					poi = poi->_n;
			}
		}

		//memcpy(arr, arrt, sz * sizeof(T));
		std::move(tarr, tarr + sz, arr);

		delete[] tarr;
		//free(arrt); 

		free(base); //delete[] base;
		free(poif); //delete[] poif;

		free(baset);
		free(poit);

		return ;
	}


	// My realization Counting Sort. Counting so slow...
	template<class T>
	void CountingSort(T *arr, unsigned int size){
		// Count
		int csz = 1024;
		//unsigned int *carr = new unsigned int[csz];
		unsigned int carr[1024];

		memset(carr, 0, csz * sizeof(unsigned int));

		unsigned int left = 0, right = size - 1;
		int i = 0, ins = left;

		while(1){
			for(unsigned int j = left; j <= right; j ++){
				//if(arr[j] >= i && arr[j] < i + csz)
				if(arr[j] <= (i - 1 + csz)){
					carr[arr[j] - i] ++;
					arr[j] = arr[left];
					left ++;
				}
			}

			// Very slow
			for(int j = 0; j < csz; j ++){
				while(carr[j]){
					arr[ins ++] = i + j;
					carr[j] --;
				}
			}

			i += csz;

			if(!i)
				break;
		}

		//delete[] carr;
	}


};


