bool TestSort(unsigned int *arr, unsigned int sz){
	for(unsigned int i = 0; i < sz - 1; i ++)
		if(arr[i] > arr[i + 1])
			return 0;

	return 1;
}


int StdSort(char *&name, unsigned int sz){
	name = "Std Sort";

	// std
	std::vector<int> v;
	v.reserve(sz);
	
	for (int i = 0; i < sz; ++i)
		v.push_back(rand());

	tbtime
	std::sort(std::begin(v), std::end(v));
	tetime;

	return tbtime_result;
}

int BinarySort(char *&name, unsigned int sz){
	name = "Binary Sort";

	// my
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

int BubbleSort(char *&name, unsigned int sz){
	name = "Bubble Sort";

	// my
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

int InversionSort(char *&name, unsigned int sz){
	name = "Inversion Sort";

	// my
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

int InsertionSort(char *&name, unsigned int sz){
	name = "Insertion Sort";

	// my
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

int BinaryInsertionSort(char *&name, unsigned int sz){
	name = "Binary Insertion Sort";

	// my
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


class TestSortResultStruct{
public:
	// Sort name
	char *name;

	// Best Size
	int sz;

	// Best time
	int tm;

};

#define TSR_SIZE		6
#define TSR_MAXTIME		1000

int TestSortMethodRun(int i, char *&name, int sz){
	switch(i){
		case 0: return StdSort(name, sz);
		case 1: return BinarySort(name, sz);
		case 2: return BubbleSort(name, sz);
		case 3: return InsertionSort(name, sz);
		case 4: return InversionSort(name, sz);
		case 5: return BinaryInsertionSort(name, sz);
	}

	return 0;
}

void TestSortMethod(int i, TestSortResultStruct &res){
	unsigned int tsz = 1024;
	char *name;

	while(1){
		int tm = TestSortMethodRun(i, name, tsz);

		printf("Test %s: %d els => %d ms.\r\n", name, tsz, tm);

		if(tm < 0)
			printf("Test %s: FAIL!\r\n", name);

		res.sz = tsz;
		res.tm = tm;

		if(tm < 0 || tm > TSR_MAXTIME)
			break;

		tsz *= 2;
	}

	res.name = name;

	return ;
}

void TestingSort(){
	TestSortResultStruct res[TSR_SIZE];

	for(int i = 0; i < TSR_SIZE; i ++)
		TestSortMethod(i, res[i]);

	printf("\r\nTesting sort results:\r\n");

	for(int i = 0; i < TSR_SIZE; i ++){
		printf("%s: %d elements => %d ms.	[%d elements in ms.] \r\n", res[i].name, res[i].sz, res[i].tm, res[i].sz / res[i].tm );
	}

	return ;
}