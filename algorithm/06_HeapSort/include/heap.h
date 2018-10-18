#ifndef HEAP
#define HEAP

#define PARENT(i) ((i-1)>>1)
#define LEFT(i) ((i<<1)+1)
#define RIGHT(i) ((i<<1)+2)

#include <iostream>

/*
MAX-HEAPIFY(A, i)
l = LEFT(i)
r = RIGHT(i)
largest = i
if l < A.heap-size and A[l] > A[i]
    largest = l
if r < A.heap-size and A[r] > A[largest]
    largest = r
if largest != i
    swap A[i] with A[largest]
    MAX-HEAPIFY(A, largest)
*/

template <class T>
void MaxHeapify(T* arr, int size, int i)
{   /*
    time: O(lgn)
    */
    int l = LEFT(i);
    int r = RIGHT(i);
    int largest = i;
    if (l < size && arr[l] > arr[i])
        largest = l;
    if (r < size && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        T tmp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = tmp;
        MaxHeapify<T>(arr, size, largest);
    }
}

/*
BUILD-MAX-HEAP(A)
A.heap-size = A.length
for i = PARENT(A.heap-size - 1) down to 0
    MAX-HEAPIFY(A, i)
*/

template <class T>
void BuildMaxHeap(T* arr, int size)
{   /*
    time: O(n)
    */
    for (int i = PARENT(size - 1); i >= 0; --i)
        MaxHeapify(arr, size, i);
}

/*
print the heap
*/

template <class T>
void PrintHeap(T* arr, int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

#endif