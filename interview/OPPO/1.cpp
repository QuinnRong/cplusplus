#include <cstdio>
#include <string>

using namespace std;

struct TreeNode
{
	char mValue = 0;
	TreeNode* pLeft = nullptr;
	TreeNode* pRight = nullptr;
};

string Decode(TreeNode* pRoot, string codes)
{
	string res = "";
	TreeNode* pTmp = pRoot;
	for (int i = 0; i < codes.size(); ++i)
	{
		if (pTmp->pLeft == nullptr && pTmp->pRight == nullptr)
		{
			res += pTmp->mValue;
			pTmp = pRoot;
		}
		if (codes[i] == '0') pTmp = pTmp->pLeft;
		else if (codes[i] = '1') pTmp = pTmp->pRight;
	}
	res += pTmp->mValue;
	return res;
}

int main()
{
	TreeNode myTree[17];
	myTree[0].pLeft = &myTree[1]; myTree[0].pRight = &myTree[2];
	myTree[1].pLeft = &myTree[3]; myTree[1].pRight = &myTree[4];
	myTree[2].pLeft = &myTree[5]; myTree[2].pRight = &myTree[6];
	myTree[3].pLeft = &myTree[7];
	myTree[4].pLeft = &myTree[8]; myTree[4].pRight = &myTree[9];
	myTree[5].pLeft = &myTree[10]; myTree[5].pRight = &myTree[11];
	myTree[6].pLeft = &myTree[12];
	myTree[7].mValue = 'b';
	myTree[8].mValue = 'a';
	myTree[9].pRight = &myTree[13];
	myTree[10].pLeft = &myTree[14];
	myTree[11].pLeft = &myTree[15];
	myTree[12].pRight = &myTree[16];
	myTree[13].mValue = 'f';
	myTree[14].mValue = 'e';
	myTree[15].mValue = 'd';
	myTree[16].mValue = 'c';

	string codes = "0100001101101010000111";
	string words = Decode(&myTree[0], codes);
	printf("%s\n", words.c_str());;
}