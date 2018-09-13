#include <algorithm>
#include <vector>
#include <cstdio>
#include <functional>

/****
@FunctionName: make_heap, push_heap, pop_heap, sort_heap
template <class RandomAccessIterator>
  void FunctionName (RandomAccessIterator first, RandomAccessIterator last); // default using operator <
template <class RandomAccessIterator, class Compare>
  void FunctionName (RandomAccessIterator first, RandomAccessIterator last, Compare comp);
****/

void MinAndMaxHeap()
{
    std::vector<int> intVector = {1,2,3,4,5};

    std::make_heap(intVector.begin(), intVector.end(), std::less<int>());    // max heap
    printf("max heap:\n");
    for (auto item : intVector)
        printf("%d ", item);
    printf("\n");
    std::sort_heap(intVector.begin(), intVector.end(), std::less<int>());
    printf("sorted max heap:\n");
    for (auto item : intVector)
        printf("%d ", item);
    printf("\n");

    std::make_heap(intVector.begin(), intVector.end(), std::greater<int>()); // min heap
    printf("min heap:\n");
    for (auto item : intVector)
        printf("%d ", item);
    printf("\n");
    std::sort_heap(intVector.begin(), intVector.end(), std::greater<int>());
    printf("sorted min heap:\n");
    for (auto item : intVector)
        printf("%d ", item);
    printf("\n");
}

void PushAndPopHeap()
{
    std::vector<int> intVector = {1,2,3,4,5};

    std::make_heap(intVector.begin(), intVector.end(), std::greater<int>()); // min heap
    printf("initial min heap:\n");
    for (auto item : intVector)
        printf("%d ", item);
    printf("\n");

    intVector.push_back(0);
    std::push_heap(intVector.begin(), intVector.end(), std::greater<int>());
    printf("min heap after push:\n");
    for (auto item : intVector)
        printf("%d ", item);
    printf("\n");

    std::pop_heap(intVector.begin(), intVector.end(), std::greater<int>());
    intVector.pop_back();
    printf("min heap after pop:\n");
    for (auto item : intVector)
        printf("%d ", item);
    printf("\n");
}

int main()
{
    MinAndMaxHeap();
    PushAndPopHeap();
}
