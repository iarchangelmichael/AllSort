
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
	void RadixSort(T *arr, unsigned int sz){
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

	template<class T>
	void BubbleSort(T *arr, unsigned int sz){
		T tmp;
		int sorted = 1;

		while(sorted){
			sorted = 0;

			for(unsigned int i = 0; i < sz - 1; i ++){
				if(arr[i] > arr[i + 1]){
					memcpy(&tmp, &arr[i], sizeof(T));
					memcpy(&arr[i], &arr[i + 1], sizeof(T));
					memcpy(&arr[i + 1], &tmp, sizeof(T));
					sorted = 1;
				}
			}
		}

		memset(&tmp, 0, sizeof(T));
	}

};


