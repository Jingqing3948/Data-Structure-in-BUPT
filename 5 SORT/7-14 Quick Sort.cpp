/*数据结构：快速排序
排序方法：
1、若待排序数据个数<=3，则直接进行插入排序
2、若待排序数据个数>3，先从待排序元素中抽取一个作为pivot（枢轴，中心点）
然后让剩下的待排序元素 小于pivot的移到左边，大于pivot的移到右边，最后pivot放在两者交界处
然后对pivot划分开的两组数据递归进行快速排序
要点
1、选取pivot的方法
    ①随便选，第一个，第二个都行。但可能出现pivot值偏小或偏大的情况，导致拆分成两组时排序时间差大（体现不出快速排序的优势）
	②第1个元素、第N个元素、第(1+N)/2个元素三者首先按大小顺序进行交换、排序，然后选取中间的作为pivot，能有效避免①的问题。
	本题中，第一次快速排序 pivot选取的是用户输入的下标对应的元素，然后先把pivot放到最右端（与Right交换），分好组后再放到该放的地方；
	之后的pivot都是采用方法②自动选取得到的，因为Left<pivot<Right，所以把pivot放到倒数第二位（与Right-1交换），分好组后再放到该放的地方
2、怎样按要求分组？
	每次进行一次快速排序后，接下来分为(Left,pivot-1)和(pivot+1,Right)两组（因为Pivot的位置确定了，不用参与排序*/
#include <stdio.h>
int jud = 1;//判断是否是第一次快速排序
int pt;

void Swap(int *a, int *b)//交换两数
{
	int temp = *a;
	*a = *b;
	*b = temp;
	return;
}

int Median3(int Left, int Right, int A[])//将A[Left],A[Right],A[(Left+Right)/2]按从小到大顺序排序，并把中心点A[(Left+Right)/2]和A[Right-1]交换
{
	int Center = (Left + Right) / 2;
	if (A[Left] > A[Center])
		Swap(&A[Left], &A[Center]);
	if (A[Left] > A[Right])
		Swap(&A[Left], &A[Right]);
	if (A[Center] > A[Right])
		Swap(&A[Center], &A[Right]);
	Swap(&A[Center], &A[Right - 1]);
	return A[Right - 1];
}

void Insertion(int Left, int Right, int A[])//插入排序，当Right-Left<3时执行
{
	for (int i = Left + 1; i <= Right; i++)
	{
		if (A[i] < A[i - 1])
		{
			int temp = A[i];
			int j = i;
			while (j - 1 >= Left && A[j - 1] > temp)
			{
				A[j] = A[j - 1];
				j--;
			}
			A[j] = temp;
		}
	}
	printf("insert(%d,%d):", Left, Right - Left + 1);
	for (int p = 0; p <= 9; p++)
	{
		printf("%d,", A[p]);
	}
	printf("\n");
}

void QSort(int Left, int Right, int A[])//快速排序
{
	int Pivot, i, j;
	if (Right - Left < 3)
	{
		Insertion(Left, Right, A);//只有3个以下元素的时候用插入排序效率更高
	}
	else
	{
		if (jud == 1)//第一次快速排序，使用用户输入的数字下标对应的元素作为pivot
		{
			Pivot = A[pt];
			//printf("A[pt]=%d\n",A[pt]);
			Swap(&A[pt], &A[Right]);
			i = Left, j = Right - 1;
			while (i < j)
			{
				while (i < j && A[i] < Pivot)
					i++;
				while (i < j && A[j] > Pivot)
					j--;
				if (i < j)
					Swap(&A[i], &A[j]);
			}
			Swap(&A[i], &A[Right]);//当两指针指向同一位置时说明排序结束，把pivot放到该处
			//printf("i=%d\n",i);
			jud = 0;//表示之后的快速排序都不再是第一次了，采用方法②选取pivot
		}
		else
		{
			Pivot = Median3(Left, Right, A);
			i = Left, j = Right - 1;
			while (i < j)
			{
				while (i < j && A[++i] < Pivot)
				{
				}
				while (i < j && A[--j] > Pivot)
				{
				}
				if (i < j)
					Swap(&A[i], &A[j]);
			}
			Swap(&A[i], &A[Right - 1]);
		}
		printf("Qsort(%d,%d):", Left, Right);
		for (int i1 = 0; i1 < 10; i1++)
			printf("%d,", A[i1]);
		printf("\n");
		//printf("i=%d\n",i);
		QSort(Left, i - 1, A);
		QSort(i + 1, Right, A);
	}
}

int main()
{
	int A[] = {49, 38, 65, 97, 76, 13, 27, 50, 2, 8};
	scanf("%d", &pt);
	QSort(0, 9, A);
	return 0;
}