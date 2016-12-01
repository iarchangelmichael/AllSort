// All Sort
// 27.11.2016 16:12

#include <Windows.h>

// Special functions & defines
#include "Special.h"

// Testing
#include "AllSort.h"

// TestType
#include "TestType.h"

// Configure:
// Max time in ms
#define TSR_MAXTIME		500
// Base type: int, int64, TestTypeInt, TestTypeStr, StaticString
#define TSR_BASETYPE	int

// Testing
#include "Test.h"

int main(){
	printf("All sort project.\r\n");

	int r1 = 0, r2 = 0, r3 = 0;
	int sz = 131072 / 128;

	//TSR_BASETYPE *arr = new TSR_BASETYPE[sz], crc = 0;						
	//for(int i = 0; i < sz; ++i){											
	//	crc += arr[i] = rand();											
	//}

	//r1 = RadixSort(131072);
	//r2 = RadixPoiSort(131072);
	//ASort::RadixPoisSort(arr, sz);
	//int r4 = RadixSort(131072 * 2);
	//int r5 = BinaryInsertionSort(sz);

	//int arr[] = { 41, 18467, 6334, 26500, 19169, 15724, 11478, 29358, 26962, 24464, 5705, 28145, 23281, 16827, 9961, 491,
	//	2995, 11942, 4827, 5436, 32391, 14604, 3902, 153, 292, 12382, 17421, 18716, 19718, 19895, 5447, 21726 };
	//ASort::RadixPoisSort(arr, sizeof(arr) / sizeof(int));


	//printf("Result: %d %d %d.", r1, r2, r3);

	//return 0;

	//int r1 = QuickSort(131072);

	//int *arr = new int[1024];
	//merge_sort(arr, 1024);

	TestingSort();

	return 0;
}