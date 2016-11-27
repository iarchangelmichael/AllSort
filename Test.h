void StdSort(){ return ;
	tbtime;

	// std
	std::vector<int> v;
	v.reserve(1000000);
	
	for (int i = 0; i < 1000000; ++i)
		v.push_back(rand());

	tctime
	std::sort(std::begin(v), std::end(v));
	tetime;

	printf("Std sort(1 000 000 elements) time %dms\r\n", tbtime_result);
}

void BinarySort(){
	tbtime;

	// my
	unsigned int *arr = new unsigned int[1000000];
	for (int i = 0; i < 1000000; ++i)
		arr[i] = rand();

	tctime;
	ASort sort;
	sort.RadixSort(arr, 1000000);
	tetime;

	delete[] arr;

	printf("Binary sort(1 000 000 elements) time %dms\r\n", tbtime_result);
}

void BubbleSort(){
	tbtime;

	// my
	unsigned int *arr = new unsigned int[1000];
	for (int i = 0; i < 1000; ++i)
		arr[i] = rand();

	tctime;
	ASort sort;
	sort.BubbleSort(arr, 1000);
	tetime;

	delete[] arr;

	printf("Binary sort(10 000 elements) time %dms\r\n", tbtime_result);
}