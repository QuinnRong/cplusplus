#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>

bool compare(const std::string &str1, const std::string str2)
{
	std::string tmp1 = str1 + str2;
	std::string tmp2 = str2 + str1;
	return (tmp1 < tmp2);
}

void PrintMinNumber(int* numbers, int length)
{
	if (numbers == nullptr || length <= 0) return;

	std::vector<std::string> strVec;
	for (int i = 0; i < length; ++i)
		strVec.push_back(std::to_string(numbers[i]));

	std::sort(strVec.begin(), strVec.end(), compare);

	for (auto item : strVec)
		printf("%s", item.c_str());
	printf("\n");
}

int main()
{
	int arr[3] = {3, 324, 321};
	PrintMinNumber(arr, sizeof(arr) / sizeof(arr[0]));
}