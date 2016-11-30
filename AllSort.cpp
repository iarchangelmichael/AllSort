// All Sort
// 27.11.2016 16:12

// Special functions & defines
#include "Special.h"

// Testing
#include "AllSort.h"

// TestType
#include "TestType.h"

// Configure:
// Max time in ms
#define TSR_MAXTIME		1000
// Base type: int, int64, TestTypeInt, TestTypeStr
#define TSR_BASETYPE	TestTypeStr

// Testing
#include "Test.h"

int main(){
	printf("All sort project.\r\n");

	//int r1 = MergeSort(256);
	//int r2 = RadixSort(131072 * 2);
	//int r3 = RadixSort(131072 * 2);
	//int r4 = RadixSort(131072 * 2);
	//int r5 = CountingSort(256 * 1024 * 1024);

	//return 0;

	//printf("Result: %d %d %d.", r1, r2, r3);

	//return 0;

	//int r1 = QuickSort(131072);

	//int *arr = new int[1024];
	//merge_sort(arr, 1024);

	TestingSort();

	return 0;
}