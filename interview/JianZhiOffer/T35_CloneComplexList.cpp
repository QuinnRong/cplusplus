#include <cstdio>
#include <map>

using namespace std;

struct ComplexListNode
{
	int mValue;
	ComplexListNode* pNext;
	ComplexListNode* pSibling;
};

ComplexListNode* Clone(ComplexListNode* pHead)
{
	if (pHead == nullptr) return nullptr;
	map<ComplexListNode*, ComplexListNode*> nodeMap;

	ComplexListNode* pCurr = pHead;
	while (pCurr != nullptr)
	{
		ComplexListNode* pClone = new ComplexListNode;
		pClone->mValue = pCurr->mValue;
		pClone->pNext = nullptr;
		pClone->pSibling = nullptr;
		nodeMap[pCurr] = pClone;
		pCurr = pCurr->pNext;
	}

	pCurr = pHead;
	while (pCurr != nullptr)
	{
		if (pCurr->pNext != nullptr)
			nodeMap[pCurr]->pNext = nodeMap[pCurr->pNext];
		if (pCurr->pSibling != nullptr)
			nodeMap[pCurr]->pSibling = nodeMap[pCurr->pSibling];
		pCurr = pCurr->pNext;
	}

	return nodeMap[pHead];
}

void PrintList(ComplexListNode* pHead)
{
	if (pHead == nullptr) return;
	printf("%d ", pHead->mValue);
	if (pHead->pSibling != nullptr) printf("%d ", pHead->pSibling->mValue);
	PrintList(pHead->pNext);
}

int main()
{
	int values[] = {1,2,3,4,5};
	ComplexListNode* pHead;
	ComplexListNode* pCurr;
	pHead = new ComplexListNode; pHead->mValue = values[0]; pHead->pNext = nullptr; pHead->pSibling = nullptr;
	pCurr = pHead;
	
	ComplexListNode* pTmp;
	for (int i = 1; i < sizeof(values) / sizeof(values[0]); ++i)
	{
		pTmp = new ComplexListNode; pTmp->mValue = values[i]; pTmp->pNext = nullptr; pTmp->pSibling = nullptr;
		pCurr->pNext = pTmp;
		pCurr = pTmp;
	}
	pHead->pSibling = pHead->pNext->pNext;
	pHead->pNext->pSibling = pHead->pNext->pNext->pNext->pNext;
	pHead->pNext->pNext->pNext->pSibling = pHead->pNext;

	PrintList(pHead);
	printf("\n");
	PrintList(Clone(pHead));

}