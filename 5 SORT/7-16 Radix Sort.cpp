/*数据结构：基数排序
说起来很容易。首先把所有数字按个位排序，然后再按十位排序，然后按百位排序……直到最高位。
题目要求输出第k次基数排序后的序列，而不一定是排好序后的序列。
*/
#include <stdio.h>
void RadixSort(int a[], int n, int exp);
int main()
{
	int x = 0;
	char y;
	int a[20];
	int top = -1;
	while ((y = getchar()) != '\n')
	{
		if (y != ',')
		{
			x = x * 10 + y - '0';
		}
		else
		{
			a[++top] = x;
			x = 0;
		}
	}
	int n = top + 1;
	int max = a[0]; //找出最大的节点，以此判断要比较多少位
	for (int i = 1; i < n; i++)
	{
		if (max < a[i])
		{
			max = a[i];
		}
	}

	int times = 0;
	int k;
	scanf("%d", &k);
	for (int exp = 1; max / exp > 0; exp = exp * 10)
	{
		RadixSort(a, n, exp);
		times++;
		if (times == k)
		{
			for (int j = 0; j < n; j++)
			{
				printf("%d,", a[j]);
			}
			break;
		}
	}

	return 0;
}
void RadixSort(int a[], int n, int exp)
{
	int bucket[10] = {0};
	int output[n]; // 临时存储排好序的数组
	//统计每一个 最后一位的数字 分别有几个数
	for (int i = 0; i < n; i++)
	{
		int last = (a[i] / exp) % 10;
		bucket[last]++;
	}
	//累计，看最后一位数（包括自己）前面一个有多少的数
	for (int i = 1; i < 10; i++)
	{
		bucket[i] = bucket[i] + bucket[i - 1];
	}
	for (int i = n - 1; i >= 0; i--)
	{
		int index, last;
		last = (a[i] / exp) % 10;
		index = --bucket[last];
		output[index] = a[i];
	}
	for (int i = 0; i < n; i++)
	{
		a[i] = output[i];
	}
}
