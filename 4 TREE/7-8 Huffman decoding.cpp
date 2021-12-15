/*数据结构：霍夫曼树
根据节点权值不同而建立的树，权值小的节点在末梢
然后左为0 右为1 以此解码
本题中给出用于通信的电文由a到h共8个字母组成，字母在电文中出现的频率为7，19，2，6，32，3，21，10
因此霍夫曼树已经建立好*/
#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100

int main()
{
	char c;
	int len=0;
	char Data[MaxSize]={'a'};
	while(scanf("%c",&c)!=EOF&&c!='\n')
	{
		Data[len++]=c;
	}
	int i=0;
	while(i<len)
	{
		if(Data[i]=='0'&&Data[i+1]=='0')
		{
			printf("b");
			i+=2;
		}
		else if(Data[i]=='0'&&Data[i+1]=='1')
		{
			printf("g");
			i+=2;
		}
		else if(Data[i]=='1'&&Data[i+1]=='1')
		{
			printf("e");
			i+=2;
		}
		else if(Data[i]=='1'&&Data[i+1]=='0'&&Data[i+2]=='0'&&Data[i+3]=='0'&&Data[i+4]=='0')
		{
			printf("c");
			i+=5;
		}
		else if(Data[i]=='1'&&Data[i+1]=='0'&&Data[i+2]=='0'&&Data[i+3]=='0'&&Data[i+4]=='1')
		{
			printf("f");
			i+=5;
		}
		else if(Data[i]=='1'&&Data[i+1]=='0'&&Data[i+2]=='0'&&Data[i+3]=='1')
		{
			printf("a");
			i+=4;
		}
		else if(Data[i]=='1'&&Data[i+1]=='0'&&Data[i+2]=='1'&&Data[i+3]=='0')
		{
			printf("d");
			i+=4;
		}
		else if(Data[i]=='1'&&Data[i+1]=='0'&&Data[i+2]=='1'&&Data[i+3]=='1')
		{
			printf("h");
			i+=4;
		}
		
		
	}
	printf("\n");
	return 0;
}
