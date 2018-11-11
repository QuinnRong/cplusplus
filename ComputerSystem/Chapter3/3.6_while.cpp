#include <iostream>

template <typename T>
T largest_fact()
{
	T n   = 1;
	T mul = n;
	T pre;
	do
	{
		pre = mul;
		mul *= ++n;
	}
	while (mul / n == pre);
	return --n;
}

int main()
{
	std::cout << "largest_fact<int>: " << largest_fact<int>() << std::endl;
	std::cout << "largest_fact<long long>: " << largest_fact<long long>() << std::endl;
}