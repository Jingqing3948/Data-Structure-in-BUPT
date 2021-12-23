/*数据结构：堆（排序）
堆排序是根据输入的序列建立完全二叉树（假设输入了n个数）从n/2到1依次排序（存数据的节点编号从1开始），比较i和i的左儿子以及i和i的右儿子（2*i和2*i+1）
比如我们建立的是大根堆，则要看是否Data[i]>Data[2*i]以及Data[2*i+1]（记得先判断有没有右儿子）
如果不符合大根堆结构，则交换i结点和他儿子中较大的一个
然后i--，再比较下一个结点，直到比较完起始节点1
本题要求对输入的数字序列进行两种（大根）堆排序，第一是输入一个排一个，第二是全部输入完之后再排。有一点点区别就是*/
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int data[100] = {0}, data1[100] = {0}, data2[100] = {0};

void exchange(int i, int n)
{
	int minchild = i * 2;
	if (i * 2 > n)
		return;
	else if (i * 2 + 1 > n)
	{
	}
	else if (data2[i * 2 + 1] < data2[i * 2])
		minchild = i * 2 + 1;
	if (data2[i] > data2[minchild])
	{
		data2[i] ^= data2[minchild];
		data2[minchild] ^= data2[i];
		data2[i] ^= data2[minchild];
		exchange(minchild, n);
	}
	return;
}

int main()
{
	int n;
	scanf("%d", &n);//输入n个元素
	scanf("%d", &data[1]);//输入的n个元素形如3,5,4,2,1
	data1[1] = data[1];
	data2[1] = data[1];
	for (int i = 2; i < n + 1; i++)
	{
		scanf(",%d", &data[i]);
		data1[i] = data[i];
		data2[i] = data[i];
		if (data1[i / 2] < data1[i])
			continue;
		else
		{
			data1[0] = data1[i];
			int j = i;
			while (j / 2 > 0 && data1[j / 2] > data1[0])//第一个堆排序
			{
				//因为输入一个元素，进行一次堆排序的方法，除了新输入的元素，之前的元素肯定都是已经符合堆排序的了
				//所以重新比较并堆排序的话，只需要比较新输入的元素所在的这一支即可
				//所以j/=2而不是j--
				data1[j] = data1[j / 2];
				j /= 2;
			}
			data1[j] = data1[0];
		}
	}
	for (int i = n / 2; i >= 1; i--)//第二个堆排序
	{
		exchange(i, n);
	}
	printf("%d", data1[1]);
	for (int i = 2; i < n + 1; i++)
	{
		printf(",%d", data1[i]);
	}
	printf("\n");
	printf("%d", data2[1]);
	for (int i = 2; i < n + 1; i++)
	{
		printf(",%d", data2[i]);
	}
	printf("\n");
	return 0;
}