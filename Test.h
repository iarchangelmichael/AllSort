const char *TestSortName [] = {"Std", "Radix", "Bubble", "Insertion", "Inversion", "BinaryInsertion", "Shell", "Heap", "Qick", "Merge", "RadixPoi" };
#define TSR_SIZE		11

bool TestSort(unsigned int *arr, unsigned int sz){
	for(unsigned int i = 0; i < sz - 1; i ++)
		if(arr[i] > arr[i + 1])
			return 0;

	return 1;
}

template<typename T>
bool TestSort(T *arr, unsigned int sz, T tcrc){
	T crc = 0;

	for(unsigned int i = 0; i < sz - 1; i ++){
		if(arr[i] > arr[i + 1] )
			return 0;

		crc += arr[i];
	}

	crc += arr[sz - 1];

	if(crc != tcrc)
		return 0;

	return 1;
}



int StdSort(unsigned int sz){
	std::vector<TSR_BASETYPE> v;
	v.reserve(sz);
	
	for (int i = 0; i < sz; ++i)
		v.push_back(rand());

	tbtime
	std::sort(std::begin(v), std::end(v));
	tetime;

	return tbtime_result;
}

#define ALLSORT_TEST_FUNCTION(funcname, testfunc)								\
int funcname(unsigned int sz){													\
	ASort sort;																	\
																				\
/*	unsigned int *arr = new unsigned int[sz], crc = 0;	*/						\
	TSR_BASETYPE *arr = new TSR_BASETYPE[sz], crc = 0;							\
	for(int i = 0; i < sz; ++i){												\
		crc += arr[i] = rand();													\
	}																			\
																				\
	tbtime;																		\
																				\
	sort.testfunc(arr, sz);														\
	tetime;																		\
																				\
	if(!TestSort(arr, sz, crc))													\
		tbtime_result *= -1;													\
																				\
	delete[] arr;																\
	return tbtime_result;														\
}

ALLSORT_TEST_FUNCTION(RadixSort, RadixSort);
ALLSORT_TEST_FUNCTION(BubbleSort, BubbleSort);
ALLSORT_TEST_FUNCTION(InversionSort, InversionSort);
ALLSORT_TEST_FUNCTION(InsertionSort, InsertionSort);
ALLSORT_TEST_FUNCTION(BinaryInsertionSort, BinaryInsertionSort);
ALLSORT_TEST_FUNCTION(ShellSort, ShellSort);
ALLSORT_TEST_FUNCTION(HeapSort, HeapSort);
ALLSORT_TEST_FUNCTION(QuickSort, QuickSort);
ALLSORT_TEST_FUNCTION(MergeSort, MergeSort);
ALLSORT_TEST_FUNCTION(CountingSort, CountingSort);
ALLSORT_TEST_FUNCTION(RadixPoiSort, RadixPoiSort);

// Test
ALLSORT_TEST_FUNCTION(RadixPoisSort, RadixPoisSort);

/*
#include <functional>

template<typename T>					
int DefaultSort(const std::function<void(T*, unsigned int)> &testfunc, unsigned int sz){	
	ASort sort;															
																		
	unsigned int *arr = new unsigned int[sz], crc = 0;					
	for(int i = 0; i < sz; ++i){										
		crc += arr[i] = rand();											
	}																	
																		
	tbtime;																
																		
	sort.testfunc(arr, sz);												
	tetime;																
																		
	if(!TestSort(arr, sz, crc))											
		tbtime_result *= -1;											
																		
	delete[] arr;														
	return tbtime_result;													
}


typedef void (ASort::*Func)() const;
int DefaultSort_(const ASort *sort, Func func, unsigned int sz){

	// my
	unsigned int *arr = new unsigned int[sz];
	for (int i = 0; i < sz; ++i)
		arr[i] = rand();

	tbtime;
	//(sort->*func)(arr, sz);
	tetime;

	if(!TestSort(arr, sz))
		tbtime_result *= -1;

	delete[] arr;
	return tbtime_result;
}*/


class TestSortResultStruct{
public:
	// Sort name
	//char *name;

	// Best Size
	int sz;

	// Best time
	int tm;
};


int TestSortMethodRun(int i, int sz){
	switch(i){
		case 0: return StdSort(sz);
		case 1: return RadixSort(sz);
		case 2: return BubbleSort(sz);
		case 3: return InsertionSort(sz);
		case 4: return InversionSort(sz);
		case 5: return BinaryInsertionSort(sz);
		case 6: return ShellSort(sz);
		case 7: return HeapSort(sz);
		case 8: return QuickSort(sz);
		case 9: return MergeSort(sz);
		case 10: return RadixPoiSort(sz);
		default: return -123456;
		//case 9: return DefaultSort(&ASort::HeapSort, sz);
	}

	return 0;
}

void TestSortMethod(int i, TestSortResultStruct &res){
	unsigned int tsz = 512;

	printf("=== New Test ===\r\n");

	while(1){
		int tm = TestSortMethodRun(i, tsz);

		printf("Test %s: %d els => %d ms.\r\n", TestSortName[i], tsz, tm);

		if(tm < 0)
			printf("Test %s: FAIL!\r\n", TestSortName[i]);

		res.sz = tsz;
		res.tm = tm;

		if(tm < 0 || tm > TSR_MAXTIME)
			break;

		tsz *= 2;
	}

	return ;
}

void TestingSort(){
	TestSortResultStruct res[TSR_SIZE];

	for(int i = 0; i < TSR_SIZE; i ++)
		TestSortMethod(i, res[i]);

	printf("\r\nTesting sort results: %s %s, TSR_MAXTIME = %d, TSR_BASETYPE = %s\r\n", tsr_os, tsr_rel, TSR_MAXTIME, TSR_TOSTRING(TSR_BASETYPE));

	for(int i = 0; i < TSR_SIZE; i ++)
		printf("%s: %d elements => %d ms.	[%d elements in ms.] \r\n", TestSortName[i], res[i].sz, res[i].tm, res[i].sz / res[i].tm );
	

	return ;
}