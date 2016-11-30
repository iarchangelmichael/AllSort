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


<b>Testing sort results:</b> Win32 Release, TSR_MAXTIME	= 100, TSR_BASETYPE = int.
<pre>
Std: 16777216 elements => 1715 ms.      [9782 elements in ms.]
Radix: 4194304 elements => 1535 ms.     [2732 elements in ms.]
Bubble: 32768 elements => 3022 ms.      [10 elements in ms.]
Insertion: 65536 elements => 1992 ms.   [32 elements in ms.]
Inversion: 32768 elements => 2255 ms.   [14 elements in ms.]
BinaryInsertion: 131072 elements => 2780 ms.    [47 elements in ms.]
Shell: 131072 elements => 1388 ms.      [94 elements in ms.]
Heap: 4194304 elements => 1542 ms.      [2720 elements in ms.]
Qick: 8388608 elements => 1029 ms.      [8152 elements in ms.]
Merge: 8388608 elements => 1584 ms.     [5295 elements in ms.]
</pre>

<b>Testing sort results:</b> Win32 Release, TSR_MAXTIME	= 100, TSR_BASETYPE = TestTypeInt.
<pre>
Std: 16777216 elements => 1745 ms.      [9614 elements in ms.]
Radix: 2097152 elements => 1065 ms.     [1969 elements in ms.]
Bubble: 32768 elements => 3075 ms.      [10 elements in ms.]
Insertion: 65536 elements => 1989 ms.   [32 elements in ms.]
Inversion: 32768 elements => 2207 ms.   [14 elements in ms.]
BinaryInsertion: 131072 elements => 2746 ms.    [47 elements in ms.]
Shell: 131072 elements => 1375 ms.      [95 elements in ms.]
Heap: 4194304 elements => 1491 ms.      [2813 elements in ms.]
Qick: 8388608 elements => 1020 ms.      [8224 elements in ms.]
Merge: 8388608 elements => 1611 ms.     [5207 elements in ms.]
</pre>

<b>Testing sort results:</b> Win32 Release, TSR_MAXTIME	= 500, TSR_BASETYPE = TestTypeStr.
<pre>
Std: 65536 elements => 684 ms.  [95 elements in ms.]
Radix: 1048576 elements => 1082 ms.     [969 elements in ms.]
Bubble: 2048 elements => 1558 ms.       [1 elements in ms.]
Insertion: 4096 elements => 676 ms.     [6 elements in ms.]
Inversion: 2048 elements => 1203 ms.    [1 elements in ms.]
BinaryInsertion: 65536 elements => 862 ms.      [76 elements in ms.]
Shell: 4096 elements => 765 ms. [5 elements in ms.]
Heap: 32768 elements => 569 ms. [57 elements in ms.]
Qick: 65536 elements => 541 ms. [121 elements in ms.]
Merge: 262144 elements => 814 ms.       [322 elements in ms.]
</pre>

<b>Testing sort results:</b> Linux Release, TSR_MAXTIME	= 1000, TSR_BASETYPE = TestTypeStr.
<pre>
Std: 65536 elements => 1453 ms. [45 elements in ms.]
Radix: 524288 elements => 1648 ms.      [318 elements in ms.]
Bubble: 1024 elements => 1113 ms.       [0 elements in ms.]
Insertion: 4096 elements => 2864 ms.    [1 elements in ms.]
Inversion: 2048 elements => 3356 ms.    [0 elements in ms.]
BinaryInsertion: 65536 elements => 2106 ms.     [31 elements in ms.]
Shell: 4096 elements => 1887 ms.        [2 elements in ms.]
Heap: 32768 elements => 1547 ms.        [21 elements in ms.]
Qick: 65536 elements => 1558 ms.        [42 elements in ms.]
Merge: 131072 elements => 1573 ms.      [83 elements in ms.]
</pre>
