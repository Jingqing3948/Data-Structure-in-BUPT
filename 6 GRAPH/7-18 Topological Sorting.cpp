/*数据结构：图，队列
拓扑排序：按有向图、流程图中的先后顺序依次输出，采用队列的方法，每次把队列中第一个元素输出并将其后继结点插入队列
本题要求先删除输入的边，然后对剩下的*/
#include <stdio.h>

void Enqueue(int Queue[], int i)//入队
{
	int a = 0;
	while (Queue[a] != -1)
		a++;
	Queue[a] = i;
	return;
}

void Dequeue(int Queue[])//出队
{
	int temp = 0;
	while (Queue[temp] != -1)
	{
		Queue[temp] = Queue[temp + 1];
		temp++;
	}
	return;
}

int main()
{
	int a[11][11];
	for (int i = 0; i < 11; i++)
		for (int j = 0; j < 11; j++)
			a[i][j] = 0;
	a[0][1] = 1;
	a[0][4] = 1;
	a[0][7] = 1;
	a[4][1] = 1;
	a[7][4] = 1;
	a[1][2] = 1;
	a[1][5] = 1;
	a[4][5] = 1;
	a[7][5] = 1;
	a[7][8] = 1;
	a[8][5] = 1;
	a[8][9] = 1;
	a[2][3] = 1;
	a[5][3] = 1;
	a[5][6] = 1;
	a[5][9] = 1;
	a[9][6] = 1;
	a[6][3] = 1;
	int print[11] = {0};
	char L, R;
	scanf("%c,%c", &L, &R);
	int l, r;
	if (L == 'S')
		l = 0;
	else
		l = L - 'A' + 1;
	if (R == 'T')
		r = 10;
	else
		r = R - 'A' + 1;
	a[l][r] = 0;
	int queue[] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,-1,-1,-1,-1,-1,-1,-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
	for (int i = 0; i <= 10; i++)
	{
		int jud = 0;
		for (int j = 0; j <= 10; j++)//判断有没有指向i节点的节点
		{
			if (a[j][i] > 0)
				jud = 1;
		}
		if (jud == 0)
			Enqueue(queue, i);
	}
	while (queue[0] != -1) //度为0的队列
	{
		//printf("queue[0]=%d\n",queue[0]);
		int first = queue[0];
		if (!print[first] && first <= 9)//输出队头的度为0的元素
		{
			if (first == 0)
				printf("S,");
			else
			{
				char x = first + 'A' - 1;
				printf("%c,", x);
			}
			print[first] = 1;
		}
		int i = first;
		for (int k = 1; k <= 9; k++)
		{
			a[i][k] = 0; //删除所有出度边
			int j = 1;
			while (j <= 9 && a[j][k] == 0) //寻找入度为0且没有输出过的边，插入队列
				j++;
			if (j == 10&&print[k] == 0&&k<=9)
			{
				Enqueue(queue, k);
			}
		}
		Dequeue(queue); //第一个元素出队
	}
	printf("T,\n");
	return 0;
}
