#include <cstdio>
#include <stack>
#include <cassert>

using namespace std;

template <typename Dtype>
class StackWithMin
{
public:
	void push(const Dtype& value);
	void pop();
	Dtype min();
private:
	stack<Dtype> mStack1;
	stack<Dtype> mStack2;
	Dtype minVal;
};

template <typename Dtype>
void StackWithMin<Dtype>::push(const Dtype& value)
{
	mStack1.push(value);
	if (mStack2.empty())
	{
		minVal = value;
	}
	else
	{
		if (value < minVal) minVal = value;
	}
	mStack2.push(minVal);
}

template <typename Dtype>
void StackWithMin<Dtype>::pop()
{
	assert(!mStack1.empty() && !mStack2.empty());
	mStack1.pop();
	mStack2.pop();
	minVal = mStack2.top();
}

template <typename Dtype>
Dtype StackWithMin<Dtype>::min()
{
	assert(!mStack1.empty() && !mStack2.empty());
	return minVal;
}

int main()
{
	StackWithMin<int> myStack;
	myStack.push(3); printf("%d\n", myStack.min());
	myStack.push(4); printf("%d\n", myStack.min());
	myStack.push(2); printf("%d\n", myStack.min());
	myStack.push(1); printf("%d\n", myStack.min());
	myStack.pop(); printf("%d\n", myStack.min());
	myStack.pop(); printf("%d\n", myStack.min());
	myStack.push(0); printf("%d\n", myStack.min());
}