#include <algorithm>
#include <vector>
#include <iostream>

/****
@algorithm
sort:
    template <class RandomAccessIterator>
      void sort (RandomAccessIterator first, RandomAccessIterator last);
    template <class RandomAccessIterator, class Compare>
      void sort (RandomAccessIterator first, RandomAccessIterator last, Compare comp);
    must be sequential container!

@cstdlib
qsort:
    void qsort (void* base, size_t num, size_t size,
                int (*compar)(const void*, const void*));
****/

int compare(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

bool myfunction(int i, int j) { return (i < j); }

struct myclass{
  bool operator() (int i,int j) { return (i < j); }
}myobject;

int main()
{
    int myints[] = {32,71,12,45,26,80,53,33};
    std::vector<int> myvector (myints, myints + 8);              // 32 71 12 45 26 80 53 33

    // using default comparison (operator <):
    std::sort(myvector.begin(), myvector.begin() + 4);           //(12 32 45 71)26 80 53 33

    // using function as comp
    std::sort(myvector.begin() + 4, myvector.end(), myfunction); // 12 32 45 71(26 33 53 80)

    // using object as comp
    std::sort(myvector.begin(), myvector.end(), myobject);       //(12 26 32 33 45 53 71 80)

    // print out content:
    for (auto item : myvector)
        std::cout << item << " ";
    std::cout << std::endl;

    int values[] = {32,71,12,45,26,80,53,33};
    qsort(values, 8, sizeof(int), compare);
    for (int i = 0; i < 8; ++i)
       printf("%d ", values[i]);
    printf("\n");
}