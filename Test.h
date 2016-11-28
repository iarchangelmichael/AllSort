bool TestSort(unsigned int *arr, unsigned int sz){
	for(unsigned int i = 0; i < sz - 1; i ++)
		if(arr[i] > arr[i + 1])
			return 0;

	return 1;
}


int StdSort(unsigned int sz){
	std::vector<int> v;
	v.reserve(sz);
	
	for (int i = 0; i < sz; ++i)
		v.push_back(rand());

	tbtime
	std::sort(std::begin(v), std::end(v));
	tetime;

	return tbtime_result;
}

int BinarySort(unsigned int sz){
	unsigned int *arr = new unsigned int[sz];
	for (int i = 0; i < sz; ++i)
		arr[i] = rand();

	tbtime;
	ASort sort;
	sort.RadixSort(arr, sz);
	tetime;

	if(!TestSort(arr, sz))
		tbtime_result *= -1;

	delete[] arr;	
	return tbtime_result;
}

int BubbleSort(unsigned int sz){
	unsigned int *arr = new unsigned int[sz];
	for (int i = 0; i < sz; ++i)
		arr[i] = rand();

	tbtime;
	ASort sort;
	sort.BubbleSort(arr, sz);
	tetime;

	if(!TestSort(arr, sz))
		tbtime_result *= -1;

	delete[] arr;	
	return tbtime_result;
}

int InversionSort(unsigned int sz){
	unsigned int *arr = new unsigned int[sz];
	for (int i = 0; i < sz; ++i)
		arr[i] = rand();

	tbtime;
	ASort sort;
	sort.InversionSort(arr, sz);
	tetime;

	if(!TestSort(arr, sz))
		tbtime_result *= -1;

	delete[] arr;	
	return tbtime_result;
}

int InsertionSort(unsigned int sz){
	unsigned int *arr = new unsigned int[sz];
	for (int i = 0; i < sz; ++i)
		arr[i] = rand();

	tbtime;
	ASort sort;
	sort.InsertionSort(arr, sz);
	tetime;

	if(!TestSort(arr, sz))
		tbtime_result *= -1;

	delete[] arr;
	return tbtime_result;
}

int BinaryInsertionSort(unsigned int sz){
	unsigned int *arr = new unsigned int[sz];
	for (int i = 0; i < sz; ++i)
		arr[i] = rand();

	tbtime;
	ASort sort;
	sort.BinaryInsertionSort(arr, sz);
	tetime;

	if(!TestSort(arr, sz))
		tbtime_result *= -1;

	delete[] arr;
	return tbtime_result;
}

int ShellSort(unsigned int sz){
	unsigned int *arr = new unsigned int[sz];
	for (int i = 0; i < sz; ++i)
		arr[i] = rand();

	tbtime;
	ASort sort;
	sort.ShellSort(arr, sz);
	tetime;

	if(!TestSort(arr, sz))
		tbtime_result *= -1;

	delete[] arr;
	return tbtime_result;
}

int HeapSort(unsigned int sz){
	unsigned int *arr = new unsigned int[sz];
	for (int i = 0; i < sz; ++i)
		arr[i] = rand();

	tbtime;
	ASort sort;
	sort.HeapSort(arr, sz);
	tetime;

	if(!TestSort(arr, sz))
		tbtime_result *= -1;

	delete[] arr;
	return tbtime_result;
}

int QuickSort(unsigned int sz){
	unsigned int *arr = new unsigned int[sz];
	for (int i = 0; i < sz; ++i)
		arr[i] = rand();

	tbtime;
	ASort sort;
	sort.QuickSort(arr, sz);
	tetime;

	if(!TestSort(arr, sz))
		tbtime_result *= -1;

	delete[] arr;
	return tbtime_result;
}

typedef void (ASort::*Func)() const;
int DefaultSort(const ASort *sort, Func func, unsigned int sz){

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
}


class TestSortResultStruct{
public:
	// Sort name
	//char *name;

	// Best Size
	int sz;

	// Best time
	int tm;
};

char *TestSortName [] = {"Std", "Binary", "Bubble", "Insertion", "Inversion", "BinaryInsertion", "Shell", "Heap", "Qick"};

#define TSR_SIZE		9
#define TSR_MAXTIME		1000

int TestSortMethodRun(int i, int sz){
	ASort sort;

	switch(i){
		case 0: return StdSort(sz);
		case 1: return BinarySort(sz);
		case 2: return BubbleSort(sz);
		case 3: return InsertionSort(sz);
		case 4: return InversionSort(sz);
		case 5: return BinaryInsertionSort(sz);
		case 6: return ShellSort(sz);
		case 7: return HeapSort(sz);
		case 8: return QuickSort(sz);
		//case 8: return DefaultSort(&sort, &ASort::HeapSort, sz);
	}

	return 0;
}

void TestSortMethod(int i, TestSortResultStruct &res){
	unsigned int tsz = 1024;
	char *name;

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

	printf("\r\nTesting sort results:\r\n");

	for(int i = 0; i < TSR_SIZE; i ++){
		printf("%s: %d elements => %d ms.	[%d elements in ms.] \r\n", TestSortName[i], res[i].sz, res[i].tm, res[i].sz / res[i].tm );
	}

	return ;
}