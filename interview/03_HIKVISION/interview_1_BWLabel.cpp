#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>

using namespace std;

void getRuns(int** image, int rows, int cols, vector<pair<pair<int, int>, pair<int, int>>>& runs)
{	/*
	input: 2D matrix with elements of 1 or 0
	output: a vector of runs: <<row, label>, <start, end>>, where label is initialized as -1
	time: O(n^2)
	*/
	for (int r = 0; r < rows; ++r)
	{
		int start, end;
		int c = 0;
		if (image[r][c] == 1)
		{
			start = c;
			if (image[r][c] == 1 && image[r][c + 1] == 0)
			{
				end = c;
				pair<int, int> rowLabel(r, -1);
				pair<int, int> startEnd(start, end);
				pair<pair<int, int>, pair<int, int>> run(rowLabel, startEnd);
				runs.push_back(run);
			}
		}
		for (c = 1; c < cols - 1; ++c)
		{
			if (image[r][c] == 1 && image[r][c - 1] == 0) start = c;
			if (image[r][c] == 1 && image[r][c + 1] == 0)
			{
				end = c;
				pair<int, int> rowLabel(r, -1);
				pair<int, int> startEnd(start, end);
				pair<pair<int, int>, pair<int, int>> run(rowLabel, startEnd);
				runs.push_back(run);
			}
		}
		if (image[r][c] == 1)
		{
			if (image[r][c] == 1 && image[r][c - 1] == 0) start = c;
			end = c;
			pair<int, int> rowLabel(r, -1);
			pair<int, int> startEnd(start, end);
			pair<pair<int, int>, pair<int, int>> run(rowLabel, startEnd);
			runs.push_back(run);
		}
	}
}

int getEquals(vector<pair<pair<int, int>, pair<int, int>>>& runs, vector<pair<int, int>>& equivalences)
{	/*
	input: a vector of runs: <<row, label>, <start, end>>, where label is initialized as -1
	output: set the labels & record connected labels in the vector equivalences;
	time: O(n^3)
	*/
	int firstRun = 0, lastRun = -1;
	int firstRunNext = 0;
	int row = 0, label = 0;
	for (int i = 0; i < runs.size(); ++i)
	{
		if (runs[i].first.first != row)
		{
			row = runs[i].first.first;
			firstRun = firstRunNext;
			lastRun = i - 1;
			firstRunNext = i;
		}
		// printf("row = %d, firstRun = %d, lastRun = %d\n", row, firstRun, lastRun);
		for (int j = firstRun; j <= lastRun; ++j)
		{
			if (runs[j].first.first == row - 1)
			{
				if (runs[i].second.first <= runs[j].second.second && runs[i].second.second >= runs[j].second.first)
				{
					if (runs[i].first.second < 0) runs[i].first.second = runs[j].first.second;
					else equivalences.push_back(make_pair(runs[i].first.second, runs[j].first.second));
				}
			}
		}
		if (runs[i].first.second < 0) runs[i].first.second = ++label;
	}
	return label;
}

void BWLabel(int** image, int rows, int cols)
{
	int** labeled = new int*[rows];
	for (int r = 0; r < rows; ++r)
	{
		labeled[r] = new int[cols];
		for (int c = 0; c < cols; ++c)
			labeled[r][c] = 0;
	}

	printf("\nstep 1:\n");
	vector<pair<pair<int, int>, pair<int, int>>> runs;
	getRuns(image, rows, cols, runs);

	vector<pair<int, int>> equivalences;
	int label = getEquals(runs, equivalences);

	for (auto run : runs)
	{
		int r = run.first.first;
		for (int c = run.second.first; c <= run.second.second; ++c)
			labeled[r][c] = run.first.second;	// set the pixal value as its label
	}
	for (int r = 0; r < rows; ++r)
	{
		for (int c = 0; c < cols; ++c)
			printf("%3d", labeled[r][c]);
		printf("\n");
	}
	for (auto eq : equivalences)
		cout << eq.first << "<==>" << eq.second << endl;

	printf("\nstep 2:\n");
	int* hash = new int[label + 1];	// quick find problem
	for (int i = 0; i <= label; ++i) hash[i] = i;
	for (auto eq : equivalences)
	{
		for (int i = 1; i <= label; ++i)
		{
			if (eq.first == hash[i]) hash[i] = eq.second;
		}
	}

	for (auto run : runs)
	{
		int r = run.first.first;
		for (int c = run.second.first; c <= run.second.second; ++c)
			labeled[r][c] = hash[run.first.second]; // set the pixal value as the connected label
	}
	for (int r = 0; r < rows; ++r)
	{
		for (int c = 0; c < cols; ++c)
			printf("%3d", labeled[r][c]);
		printf("\n");
	}
	printf("hash:\n");
	for (int i = 0; i <= label; ++i) printf("%d ", hash[i]);
	printf("\n");

	printf("\nstep 3:\n");
	unordered_map<int, int> filled;	// calculate num of pixals for every label
	filled[0] = 0;
	for (int r = 0; r < rows; ++r)
	{
		for (int c = 0; c < cols; ++c)
		{
			if (labeled[r][c])
			{
				if (filled.find(labeled[r][c]) == filled.end()) filled[labeled[r][c]] = 1;
				else ++filled[labeled[r][c]];
			}
		}
	}

	for (int r = 0; r < rows; ++r)
	{
		for (int c = 0; c < cols; ++c)
			printf("%3d", filled[labeled[r][c]]);	// print num of connected pixals at corresponding place
		printf("\n");
	}
	printf("map:\n");
	for (int i = 0; i <= label; ++i) printf("%d ", filled[hash[i]]);
	printf("\n");

	delete[] labeled;
	delete[] hash;
}

int main()
{
	freopen("interview_1.txt", "r", stdin);
	int rows, cols;
	cin >> rows >> cols;
	int** image = new int*[rows];
	for (int r = 0; r < rows; ++r)
	{
		image[r] = new int[cols];
		for (int c = 0; c < cols; ++c)
			cin >> image[r][c];
	}

	printf("step 0:\n");
	for (int r = 0; r < rows; ++r)
	{
		for (int c = 0; c < cols; ++c)
			printf("%3d", image[r][c]);
		printf("\n");
	}

	BWLabel(image, rows, cols);

	fclose(stdin);
	delete[] image;
	return 0;
}