/*数据结构：循环队列
输入n,t,n个人围成圈坐在一起，从第一个人开始数，每数t个人就踢掉一个人
如输入5，1，踢掉的顺序是2,4,1,5,3
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct listnode{
	int num;
	struct listnode *next;
}listnode,*List,*ListNode;

int main()
{
	int n,t;
	List L=(ListNode)malloc(sizeof(listnode));	//1号节点（该循环链表无头结点） 
	ListNode temp=L;
	L->num=1;
	L->next=NULL;
	scanf("%d,%d",&n,&t);
	if(n==1)
	{
		printf("1\n");
		return 0;
	}
	for(int i=2;i<=n;i++){						 //2~n号节点 
		temp->next=(ListNode)malloc(sizeof(listnode));
		temp=temp->next;
		temp->num=i;
		temp->next=NULL;
	}
	temp->next=L;								//头尾相接 
	temp=L;										//从头开始 
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<t-1;j++)
		{
			temp=temp->next;
		}
		printf("%d,",temp->next->num);
		ListNode a=temp->next->next;
		free(temp->next);
		temp->next=a;
		temp=temp->next;
	}
	printf("%d\n",temp->num);
	free(temp);
	return 0;
}
