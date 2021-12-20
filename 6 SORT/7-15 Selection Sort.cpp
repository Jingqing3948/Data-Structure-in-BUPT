/*数据结构：选择排序
每一趟从头到尾选出最小的元素放在开头
还算简单，就不赘述啦*/
#include <stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	int Data[20];
	for (int i = 0; i < n; i++)
	{
		scanf("%d,", &Data[i]);
	}
	for (int i = 0; i < n - 1; i++)
	{
		int minindex = i;
		int j = i;
		for (; j < n; j++)
		{
			if (Data[j] < Data[minindex])
				minindex = j;
		}
		int temp = Data[i];
		Data[i] = Data[minindex];
		Data[minindex] = temp;
		for (int I = 0; I < n; I++)
		{
			printf("%d,", Data[I]);
		}
		printf("\n");
	}
}