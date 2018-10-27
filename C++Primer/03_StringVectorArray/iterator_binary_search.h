#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <iterator>

template <typename ITER, typename V>
ITER binary_search(ITER beg, ITER end, V sought)
{
	auto mid = beg + (end - beg) / 2;
	while (mid != end && *mid != sought)
	{
		if (*mid > sought)
			end = mid;
		else
			beg = mid + 1;
		mid = beg + (end - beg) / 2;
	}
	return mid;
}

template <typename T, typename V>
typename T::const_iterator binary_search(const T& data, V sought)
{
	return binary_search(data.cbegin(), data.cend(), sought);
}

#endif