#include <cstdio>
#include <stack>

using namespace std;

bool isPopOrder(const int* pPush, const int* pPop, int len)
{
	if (pPush == nullptr || pPop == nullptr || len <= 0) return false;

	stack<int> pushStack;
	int popId = 0;
	for (int i = 0; i < len; ++i)
	{
		pushStack.push(pPush[i]);
		while (!pushStack.empty() && popId < len && pushStack.top() == pPop[popId])
		{
			pushStack.pop();
			++popId;
		}
	}
	if (pushStack.empty() && popId == len) return true;
	return false;
}

int main()
{
	int pPush[] = {1,2,3,4,5};
	int pPop1[] = {4,5,3,2,1};
	printf("%s\n", isPopOrder(pPush, pPop1, 5)?"yes":"no");
	int pPop2[] = {4,3,5,1,2};
	printf("%s\n", isPopOrder(pPush, pPop2, 5)?"yes":"no");
}