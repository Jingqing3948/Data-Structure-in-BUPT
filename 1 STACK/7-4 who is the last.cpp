/*���ݽṹ��ѭ������
����n,t,n����Χ��Ȧ����һ�𣬴ӵ�һ���˿�ʼ����ÿ��t���˾��ߵ�һ����
������5��1���ߵ���˳����2,4,1,5,3
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
	List L=(ListNode)malloc(sizeof(listnode));	//1�Žڵ㣨��ѭ��������ͷ��㣩 
	ListNode temp=L;
	L->num=1;
	L->next=NULL;
	scanf("%d,%d",&n,&t);
	if(n==1)
	{
		printf("1\n");
		return 0;
	}
	for(int i=2;i<=n;i++){						 //2~n�Žڵ� 
		temp->next=(ListNode)malloc(sizeof(listnode));
		temp=temp->next;
		temp->num=i;
		temp->next=NULL;
	}
	temp->next=L;								//ͷβ��� 
	temp=L;										//��ͷ��ʼ 
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
