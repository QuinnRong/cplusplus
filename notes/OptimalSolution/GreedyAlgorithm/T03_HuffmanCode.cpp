#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

struct TreeNode
{
	int freq;
	char chr;
	TreeNode* pLeft;
	TreeNode* pRight;
};

bool cmp(TreeNode* a, TreeNode* b)
{
	return (a->freq > b->freq);
}

TreeNode* CreateHuffman(TreeNode* Leaves, TreeNode* Nodes, int n)
{
	vector<TreeNode*> minHeap;
	for (int i = 0; i < n; ++i)
	{
		minHeap.push_back(&Leaves[i]);
	}
	make_heap(minHeap.begin(), minHeap.end(), cmp);

	for (int i = 0; i < n - 1; ++i)
	{
		Nodes[i].pLeft = minHeap[0];
		pop_heap(minHeap.begin(), minHeap.end(), cmp); minHeap.pop_back();
		Nodes[i].pRight = minHeap[0];
		pop_heap(minHeap.begin(), minHeap.end(), cmp); minHeap.pop_back();
		Nodes[i].freq = Nodes[i].pLeft->freq + Nodes[i].pRight->freq;
		minHeap.push_back(&Nodes[i]); push_heap(minHeap.begin(), minHeap.end(), cmp);
	}
	return minHeap[0];
}

void HuffmanMap(TreeNode* pRoot, string& tmp, map<char, string>& codeMap)
{
	if (pRoot == nullptr) return;
	if (pRoot->pLeft == nullptr && pRoot->pRight == nullptr)
		codeMap.emplace(pRoot->chr, tmp);
	tmp.push_back('0'); HuffmanMap(pRoot->pLeft, tmp, codeMap);	tmp.pop_back();
	tmp.push_back('1');	HuffmanMap(pRoot->pRight, tmp, codeMap); tmp.pop_back();
}

string HuffmanEncode(TreeNode* HuffmanTree, const string& str)
{
	map<char, string> codeMap;
	string tmp = "";
	HuffmanMap(HuffmanTree, tmp, codeMap);
	// for (auto i : codeMap)
	// 	cout << i.first << "->" << i.second << endl;

	string res = "";
	for (int i = 0; i < str.size(); ++i)
		res += codeMap[str[i]];
	return res;
}

string HuffmanDecode(TreeNode* HuffmanTree, const string& str)
{
	string res = "";
	TreeNode* tmp = HuffmanTree;
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] == '0') tmp = tmp->pLeft;
		else if (str[i] == '1') tmp = tmp->pRight;
		if (tmp->pLeft == nullptr && tmp->pRight == nullptr)
		{
			res += tmp->chr;
			tmp = HuffmanTree;
		}
	}
	return res;
}

int main()
{
	freopen("3.txt", "r", stdin);
	int n;
	cin >> n;
	TreeNode* Leaves = new TreeNode[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> Leaves[i].chr >> Leaves[i].freq;
		Leaves[i].pLeft = nullptr;			// important!
		Leaves[i].pRight = nullptr;			// important!
	}

	TreeNode* Nodes = new TreeNode[n - 1];	// n - 1 个内部节点
	TreeNode* HuffmanTree = CreateHuffman(Leaves, Nodes, n);
	
	string str;
	cin >> str;
	string code = HuffmanEncode(HuffmanTree, str);
	cout << str << ": " << code << endl;

	string decode = HuffmanDecode(HuffmanTree, code);
	cout << code << ": " << decode << endl;

	delete[] Leaves;
	delete[] Nodes;
	fclose(stdin);
	return 0;
}