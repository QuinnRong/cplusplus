#include <stack>
#include <cstdio>
#include <stdexcept>

using namespace std;

template <typename T>
class CQueue
{
public:
	CQueue() {};
	~CQueue() {};

	void appendTail(const T& node);
	T deleteHead();

private:
	stack<T> stack1;
	stack<T> stack2;
};

template <typename T>
void CQueue<T>::appendTail(const T& node)
{
	stack1.push(node);
}

template <typename T>
T CQueue<T>::deleteHead()
{
	if (stack2.empty())
	{
		while (!stack1.empty())
		{
			stack2.push(stack1.top());
			stack1.pop();
		}
	}

	if (stack2.empty()) throw runtime_error("empty queue!");

	T res= stack2.top();
	stack2.pop();
	return res;
}

int main()
{
	CQueue<char> myQueue;
	myQueue.appendTail('a');
	myQueue.appendTail('b');
	myQueue.appendTail('c');
	printf("%c\n", myQueue.deleteHead());
	printf("%c\n", myQueue.deleteHead());
	myQueue.appendTail('d');
	printf("%c\n", myQueue.deleteHead());
	printf("%c\n", myQueue.deleteHead());
	printf("%c\n", myQueue.deleteHead());
}