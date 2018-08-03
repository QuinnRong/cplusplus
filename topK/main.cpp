#include <cstdio>
#include <cstdlib>
#include <ctime>

#include "topK.h"

#define N 30000
#define K 5

void GetData(float *library)
{
    // srand (time(NULL));
    srand (0);
    for (int i = 0; i < N; ++i)
    {
        library[i] = rand() * 100.0 / RAND_MAX;
        // library[i] = i;
        // library[i] = N - i;
    }
}

void PrintResult(float *topValue, int *topIndex, int start, int end)
{
    for (int i = start; i < end; ++i)
    {
     printf("[%d] %f(%d)\n", i, topValue[i], topIndex[i]);
    }
    printf("\n");
}

int main()
{
    static float library[N];
    float topValue[K];
    int topIndex[K];

    GetData(library);
    printf("Array topN increase order:\n");
    ArrayTopNInc(library, topValue, topIndex, N, K);
    PrintResult(topValue, topIndex, 0, 5);

    GetData(library);
    printf("Array topN decrease order:\n");
    ArrayTopNDec(library, topValue, topIndex, N, K);
    PrintResult(topValue, topIndex, K - 5, K);

    GetData(library);
    printf("Heap topN increase order:\n");
    HeapTopNInc(library, topValue, topIndex, N, K);
    PrintResult(topValue, topIndex, 0, 5);

    GetData(library);
    printf("Heap topN decrease order:\n");
    HeapTopNDec(library, topValue, topIndex, N, K);
    PrintResult(topValue, topIndex, K - 5, K);
}