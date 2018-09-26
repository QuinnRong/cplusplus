#include<iostream>
using namespace std;
 
void findpath(int * a,int start,int n,int * path,int top,int sum)//start表示每个子问题从数组a的什么位置开始
{
	for(int i=start;i<n;i++)
	{
		sum -= a[i];
		path[top++]=i;//path记录每一条经过的路径
		if(sum == 0)
		{
			for(int j=0;j<top;j++)
			{
				cout<<a[path[j]]<<" ";
			}
			cout<<endl;
		}
		else if(sum > 0)
		{
			findpath(a,i+1,n,path,top,sum);
		}
		sum +=a[i];
		top--;
	}
}
 
int main()
{
	int a[]={5,8,6,3,2,4,7,1,9,10};
	int path[10]={0};
	findpath(a,0,10,path,0,20);
	return 0;
}
