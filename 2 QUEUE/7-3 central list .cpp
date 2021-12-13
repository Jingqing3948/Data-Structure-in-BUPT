/*数据结构：栈，队列（初涉） 
检查输入的序列是否是回文的，如1,3,5,7,9,7,5,3,1或1,2,3,3,2,1 
一开始想的是先输入，入栈，然后序列开始和前面重叠时依次出栈进行检查。
但是问题在于中间有一个单独的数字不是很好处理
后来发现另一种解法，我们建立一个队列一个栈，两个结构都存入输入队列
比较的时候，栈从后往前出栈，队列从前往后出队，并依次匹配比较*/ 
#include<stdio.h>
#include<string.h>
int main()
{
	int Stack[100]={0};
	int Queue[100]={0};
	int n;
	int i=-1;
	while(scanf("%d,",&n)!=EOF&&n!='\n')
	{
		Stack[1+i]=n;
		Queue[++i]=n;
	}
	int j=0;
	for(;i>=0;i--)
	{
		if(Queue[j++]!=Stack[i])
		{
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	return 0;
}
