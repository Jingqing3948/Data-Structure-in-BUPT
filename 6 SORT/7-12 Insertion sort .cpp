/*数据结构：插入排序
如排序要求是从小到大排序，从第二个元素开始，每次把该元素插入到前面已经排好的序列中
道理很简单~做起来有点绕，像冒泡排序*/
#include<stdio.h>
#define MaxSize 20
int main()
{
	int n;
	int Element[MaxSize];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d,",&Element[i]);
	}
	for(int i=1;i<n;i++)
	{
		if(Element[i-1]<Element[i]){}//如果第i个元素刚好是最大的元素，那么正好不用排序
		else 
		{
			int temp=Element[i];
			int ptr=i-1;
			do{
				Element[ptr+1]=Element[ptr];
				ptr--;
			}while(ptr>=0&&Element[ptr]>temp);
			Element[ptr+1]=temp;
		}
		for(int p=0;p<n;p++)
		{
			printf("%d,",Element[p]);
		}
		printf("\n");
	}
	return 0;
} 
