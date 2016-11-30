# AllSort
<h2>All variant of sort</h2>


<b>Test:</b>

Sort unsigned int arr[elements];

<b>Std:</b>

Use std::sort.

<b>Radix:</b>

https://en.wikipedia.org/wiki/Radix_sort

https://ru.wikipedia.org/wiki/Поразрядная_сортировка


<b>Bubble:</b>

https://en.wikipedia.org/wiki/Bubble_sort

https://ru.wikipedia.org/wiki/Сортировка_пузырьком


<b>Insertion:</b>

https://en.wikipedia.org/wiki/Insertion_sort

https://ru.wikipedia.org/wiki/Сортировка_вставками 


<b>Inversion:</b>
???

<b>BinaryInsertion:</b>

Insertion + https://en.wikipedia.org/wiki/Upper_and_lower_bounds


<b>Shell:</b>

https://en.wikipedia.org/wiki/Shellsort

https://ru.wikipedia.org/wiki/Сортировка_Шелла


<b>Heap:</b>

https://en.wikipedia.org/wiki/Heapsort

https://ru.wikipedia.org/wiki/Пирамидальная_сортировка


<b>Qick:</b>

https://en.wikipedia.org/wiki/Quicksort

https://ru.wikipedia.org/wiki/Быстрая_сортировка

<b>Counting sort:</b> (Not in test. So slow.)

https://en.wikipedia.org/wiki/Counting_sort

https://ru.wikipedia.org/wiki/Сортировка_подсчётом 



<b>Debug programm output:</b>

<pre>
Testing sort results:
Std: 1048576 elements => 1523 ms.       [688 elements in ms.]
Radix: 2097152 elements => 1189 ms.     [1763 elements in ms.]
Bubble: 8192 elements => 2179 ms.       [3 elements in ms.]
Insertion: 32768 elements => 2951 ms.   [11 elements in ms.]
Inversion: 8192 elements => 1855 ms.    [4 elements in ms.]
BinaryInsertion: 131072 elements => 1916 ms.    [68 elements in ms.]
Shell: 16384 elements => 1261 ms.       [12 elements in ms.]
Heap: 524288 elements => 1182 ms.       [443 elements in ms.]
Qick: 2097152 elements => 1877 ms.      [1117 elements in ms.]
Merge: 1048576 elements => 1906 ms.     [550 elements in ms.]

Testing sort results:
Std: 524288 elements => 1437 ms.        [364 elements in ms.]
Binary: 1024 elements => -1 ms. [-1024 elements in ms.]
Bubble: 4096 elements => 1148 ms.       [3 elements in ms.]
Insertion: 16384 elements => 1240 ms.   [13 elements in ms.]
Inversion: 8192 elements => 3698 ms.    [2 elements in ms.]
BinaryInsertion: 131072 elements => 3471 ms.    [37 elements in ms.]
Shell: 16384 elements => 1957 ms.       [8 elements in ms.]
Heap: 524288 elements => 1833 ms.       [286 elements in ms.]
Qick: 1048576 elements => 1274 ms.      [823 elements in ms.]
Merge: 524288 elements => 1906 ms.      [275 elements in ms.]

Testing sort results:
Std: 1048576 elements => 1757 ms.       [596 elements in ms.]
Binary: 16384 elements => -1 ms.        [-16384 elements in ms.]
Bubble: 8192 elements => 2192 ms.       [3 elements in ms.]
Insertion: 32768 elements => 2730 ms.   [12 elements in ms.]
Inversion: 8192 elements => 1747 ms.    [4 elements in ms.]
BinaryInsertion: 131072 elements => 2082 ms.    [62 elements in ms.]
Shell: 16384 elements => 1208 ms.       [13 elements in ms.]
Heap: 524288 elements => 1235 ms.       [424 elements in ms.]
Qick: 2097152 elements => 1876 ms.      [1117 elements in ms.]

</pre>


<b>Release programm output:</b>

<pre>
Testing sort results:
Std: 16777216 elements => 1456 ms.      [11522 elements in ms.]
Radix: 4194304 elements => 1664 ms.     [2520 elements in ms.]
Bubble: 32768 elements => 2348 ms.      [13 elements in ms.]
Insertion: 65536 elements => 1698 ms.   [38 elements in ms.]
Inversion: 32768 elements => 1735 ms.   [18 elements in ms.]
BinaryInsertion: 131072 elements => 2114 ms.    [62 elements in ms.]
Shell: 131072 elements => 1101 ms.      [119 elements in ms.]
Heap: 4194304 elements => 1412 ms.      [2970 elements in ms.]
Qick: 8388608 elements => 1593 ms.      [5265 elements in ms.]
Merge: 8388608 elements => 1234 ms.     [6797 elements in ms.]

Testing sort results:
Std: 8388608 elements => 1077 ms.       [7788 elements in ms.]
Binary: 8192 elements => -1 ms. [-8192 elements in ms.]
Bubble: 32768 elements => 3863 ms.      [8 elements in ms.]
Insertion: 65536 elements => 2272 ms.   [28 elements in ms.]
Inversion: 32768 elements => 2667 ms.   [12 elements in ms.]
BinaryInsertion: 131072 elements => 3344 ms.    [39 elements in ms.]
Shell: 131072 elements => 1710 ms.      [76 elements in ms.]
Heap: 4194304 elements => 1895 ms.      [2213 elements in ms.]
Qick: 4194304 elements => 1138 ms.      [3685 elements in ms.]
Merge: 8388608 elements => 1935 ms.     [4335 elements in ms.]


Testing sort results:
Std: 16777216 elements => 1357 ms.      [12363 elements in ms.]
Binary: 2048 elements => -1 ms. [-2048 elements in ms.]
Bubble: 32768 elements => 2253 ms.      [14 elements in ms.]
Insertion: 65536 elements => 1471 ms.   [44 elements in ms.]
Inversion: 32768 elements => 1795 ms.   [18 elements in ms.]
BinaryInsertion: 131072 elements => 2083 ms.    [62 elements in ms.]
Shell: 131072 elements => 1537 ms.      [85 elements in ms.]
Heap: 4194304 elements => 1348 ms.      [3111 elements in ms.]
Qick: 16777216 elements => 1306 ms.     [12846 elements in ms.]

</pre>
