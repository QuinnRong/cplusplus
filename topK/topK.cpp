#include <cstdio>
#include <ctime>

#include "topK.h"

void BubbleSortInc(float *array, int *index, const int num, const int step)
{   /*
    bubble sort an num-length array multiple steps from head to back;
    requirement: 0 <= step <= num - 1;
    fully sort : step = num - 1;
    */
    for (int s = 0; s < step; ++s)
    {
        for (int idx = 0; idx < num - s- 1; ++idx)
        {
            if (array[idx] > array[idx + 1])
            {
                float tmpV = array[idx];
                array[idx] = array[idx + 1];
                array[idx + 1] = tmpV;
                int tmpI = index[idx];
                index[idx] = index[idx + 1];
                index[idx + 1] = tmpI;
            }
        }
    }
}

void BubbleSortDec(float *array, int *index, const int num, const int step)
{   /*
    bubble sort an num-length array multiple steps from back to head;
    requirement: 0 <= step <= num - 1;
    fully sort : step = num - 1;
    */
    for (int s = 0; s < step; ++s)
    {
        for (int idx = num - 1; idx > s; --idx)
        {
            if (array[idx] > array[idx - 1])
            {
                float tmpV = array[idx];
                array[idx] = array[idx - 1];
                array[idx - 1] = tmpV;
                int tmpI = index[idx];
                index[idx] = index[idx - 1];
                index[idx - 1] = tmpI;
            }
        }
    }
}

void ShiftDown(float *array, int *index, const int num, const int i)
{   /*
    shift down ith element in a min-heap of size num;
    requirement: 0 <= i <= num - 1;
    */
    int left = i * 2 + 1;
    int right = i * 2 + 2;
    int next;
    float tmpV;
    float tmpI;
    if (left > num - 1)
    {
        return;
    }
    else
    {
        if (right > num - 1)
        {
            next = left;
        }
        else
        {
            next = (array[left] < array[right]) ? left : right;
        }
        if (array[i] > array[next])
        {
            tmpV = array[i];
            array[i] = array[next];
            array[next] = tmpV;
            tmpI = index[i];
            index[i] = index[next];
            index[next] = tmpI;
            ShiftDown(array, index, num, next);
        }
    }
}

void ArrayTopNInc(float *library, float *topValue, int *topIndex, const int N, const int K)
{
    clock_t start = clock();

    // initialize
    for (int i = 0; i < K; ++i)
    {
        topValue[i] = library[i];
        topIndex[i] = i;
    }
    // bubble sort 0 ~ K - 1
    BubbleSortInc(topValue, topIndex, K, K - 1);
    // bubble sort K ~ N -1
    for (int i = K; i < N; ++i)
    {
        if (library[i] > topValue[0])
        {
            topValue[0] = library[i];
            topIndex[0] = i;
            BubbleSortInc(topValue, topIndex, K, 1);
        }
    }

    clock_t stop = clock();
    printf("time: %f ms\n", (stop - start) * 1000.0 / CLOCKS_PER_SEC);
}

void ArrayTopNDec(float *library, float *topValue, int *topIndex, const int N, const int K)
{
    clock_t start = clock();

    // initialize
    for (int i = 0; i < K; ++i)
    {
        topValue[i] = library[i];
        topIndex[i] = i;
    }
    // bubble sort 0 ~ K - 1
    BubbleSortDec(topValue, topIndex, K, K - 1);
    // bubble sort K ~ N -1
    for (int i = K; i < N; ++i)
    {
        if (library[i] > topValue[K - 1])
        {
            topValue[K - 1] = library[i];
            topIndex[K - 1] = i;
            BubbleSortDec(topValue, topIndex, K, 1);
        }
    }

    clock_t stop = clock();
    printf("time: %f ms\n", (stop - start) * 1000.0 / CLOCKS_PER_SEC);
}

void HeapTopNInc(float *library, float *topValue, int *topIndex, const int N, const int K)
{
    clock_t start = clock();

    // initialize
    for (int i = 0; i < K; ++i)
    {
        topValue[i] = library[i];
        topIndex[i] = i;
    }
    // create min heap (0 ~ K - 1)
    for (int i = (K - 1) / 2; i >= 0; --i)
    {
        ShiftDown(topValue, topIndex, K, i);
    }
    // heap sort (K ~ N - 1)
    for (int i = K; i < N; ++i)
    {
        if (library[i] > topValue[0])
        {
            topValue[0] = library[i];
            topIndex[0] = i;
            ShiftDown(topValue, topIndex, K, 0);
        }
    }
    // bubble sort 0 ~ K - 1
    BubbleSortInc(topValue, topIndex, K, K - 1);

    clock_t stop = clock();
    printf("time: %f ms\n", (stop - start) * 1000.0 / CLOCKS_PER_SEC);
}

void HeapTopNDec(float *library, float *topValue, int *topIndex, const int N, const int K)
{
    clock_t start = clock();

    // initialize
    for (int i = 0; i < K; ++i)
    {
        topValue[i] = library[i];
        topIndex[i] = i;
    }
    // create min heap (0 ~ K - 1)
    for (int i = (K - 1) / 2; i >= 0; --i)
    {
        ShiftDown(topValue, topIndex, K, i);
    }
    // heap sort (K ~ N - 1)
    for (int i = K; i < N; ++i)
    {
        if (library[i] > topValue[0])
        {
            topValue[0] = library[i];
            topIndex[0] = i;
            ShiftDown(topValue, topIndex, K, 0);
        }
    }
    // bubble sort 0 ~ K - 1
    BubbleSortDec(topValue, topIndex, K, K - 1);

    clock_t stop = clock();
    printf("time: %f ms\n", (stop - start) * 1000.0 / CLOCKS_PER_SEC);
}