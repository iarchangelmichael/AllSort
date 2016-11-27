// All Sort
// 27.11.2016 16:12


// Special functions & defines
#include "Special.h"

// Testing
#include "AllSort.h"

// Testing
#include "Test.h"

int main(){
	printf("All sort project.\r\n");

	for(int i = 0; i < 5; i ++){
		StdSort();
		BinarySort();
		BubbleSort();
	}

	return 0;
}