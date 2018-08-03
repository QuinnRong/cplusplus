#ifndef TOPN_H
#define TOPN_H

void BubbleSortInc(float *array, int *index, const int num, const int step);
void ArrayTopNInc(float *library, float *topValue, int *topIndex, const int num, const int topk);
void BubbleSortDec(float *array, int *index, const int num, const int step);
void ArrayTopNDec(float *library, float *topValue, int *topIndex, const int num, const int topk);

void ShiftDown(float *array, int *index, const int num, const int i);
void HeapTopNDec(float *library, float *topValue, int *topIndex, const int N, const int K);
void HeapTopNInc(float *library, float *topValue, int *topIndex, const int N, const int K);

#endif