#include <vector>
using std::vector;

#include <iostream>
using std::cin; using std::cout; using std::endl;

int main()
{
	freopen("data/vector_scores.txt", "r", stdin);
	vector<unsigned> scores(11, 0);
	unsigned grade;
	while (cin >> grade)
		if (grade <= 100)
			++scores[grade / 10];
	for (auto i : scores)
		cout << i << " ";
	cout << endl;
	return 0;
}

/**
 * result:
 * 0 0 0 1 1 0 2 3 2 4 1
 */