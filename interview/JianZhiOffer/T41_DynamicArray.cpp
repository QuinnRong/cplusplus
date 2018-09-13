#include <cstdio>
#include <algorithm>
#include <vector>
#include <stdexcept>

template <typename T> class DynamicArray
{
public:
	void Insert(T num)
	{
		if (((minHeap.size() + maxHeap.size()) & 0x1) == 0)
		{
			if (minHeap.size() > 0 && num > minHeap.front())
			{
				minHeap.push_back(num);
				std::push_heap(minHeap.begin(), minHeap.end(), std::greater<T>());
				num = minHeap.front();
				std::pop_heap(minHeap.begin(), minHeap.end(), std::greater<T>());
				minHeap.pop_back();
			}
			maxHeap.push_back(num);
			std::push_heap(maxHeap.begin(), maxHeap.end(), std::less<T>());
		}
		else
		{
			if (maxHeap.size() > 0 && num < maxHeap.front())
			{
				maxHeap.push_back(num);
				std::push_heap(maxHeap.begin(), maxHeap.end(), std::less<T>());
				num = maxHeap.front();
				std::pop_heap(maxHeap.begin(), maxHeap.end(), std::less<T>());
				maxHeap.pop_back();
			}
			minHeap.push_back(num);
			std::push_heap(minHeap.begin(), minHeap.end(), std::greater<T>());
		}
	}
	T GetMedian()
	{
		int size = maxHeap.size() + minHeap.size();
		// printf("maxHeap size = %d, minHeap size = %d\n", maxHeap.size(), minHeap.size());
		if (size == 0)
			throw std::runtime_error("No numbers available!");
		if ((size & 0x1) == 1) return maxHeap.front();
		else return ((maxHeap.front() + minHeap.front()) / 2);
	}
private:
	std::vector<T> maxHeap;
	std::vector<T> minHeap;
};

int main()
{
	DynamicArray<int> myArray;
	for (int i = 0; i < 10; ++i)
	{
		myArray.Insert(i);
		printf("%d\n", myArray.GetMedian());
	}
}