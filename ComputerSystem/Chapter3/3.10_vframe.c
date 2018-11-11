#include <iostream>

void vframe(int n)
{
	double arr[n];
	for (int i = 0; i < n; ++i)
		arr[i] = i;
	std::cout << static_cast<const void*> (arr) << std::endl;
	for (int i = 0; i < n; ++i)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

int main()
{
	freopen("data/vframe.txt", "r", stdin);

	int n;
	std::cin >> n;
	vframe(n);
	std::cin >> n;
	vframe(n);

	fclose(stdin);
}

/*
 * 0x61fdb0
 * 0 1 2 3 4
 * 0x61fd90
 * 0 1 2 3 4 5 6 7 8 9
 */