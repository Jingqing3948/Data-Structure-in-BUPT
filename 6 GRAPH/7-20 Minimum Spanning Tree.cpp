/*���ݽṹ����С������
ͼ������������С��ͨ��ͼ
��ͨͼ��ͼ�����ж��㶼��ͨ
Ҳ����˵ͼ���������������ٵı߰����ж�����ͨ����
��ͼ����С���������Ǳ�Ȩֵ��С��������
Prim�㷨������ѡ��һ��������Ϊ���ĸ��ڵ㣬Ȼ��ÿ�ΰѴ�����С���½�������
Kruskal�㷨����ͼ���ҵ�Ȩֵ��С�ıߣ�ʹ�ñ���ͷ�����������ͨ������Ѿ���ͨ�˾ͺ��ԣ�ֱ�����ж��㶼������ͨͼ
�����Ҳ��õ���Kruskal�㷨���ٴ�ʹ����һЩ���ཻ����֪ʶ
��ĿҪ������ͼ�Ѿ������ˡ��������A~J�����������±��е�1~10��ʾ
Ȼ�������ӵıߵ�ȨֵҲ�Ѹ���
�����������㣬�Լ�һ��Ȩֵ���޸ĸ�ͼ�е�һ���ߵ�Ȩֵ����A,B,1��
Ȼ���С���������������С�������еıߵ�Ȩֵ����Ҳ����ѡ��Kruskal�㷨��ԭ��֮һ��*/
#include<stdio.h>

void Union(int S[],int root1,int root2)//�ϲ�������ͨ�� 
{
	
	S[root2]=root1;
	return;
}

int Find(int S[],int root)//����root������������ͨ�� 
{
	if(S[root]==0)return root;
	else return Find(S,S[root]);
}

void Swap(char *a,char *b)
{
	char temp=*a;
	*a=*b;
	*b=temp;
	return;
}

int main()
{
	int A[11][11];
	for(int i=0;i<11;i++)for(int j=0;j<11;j++)A[i][j]=0;
	A[1][2]=3;
	A[1][4]=4;
	A[1][5]=4;
	A[2][5]=2;
	A[2][6]=3;
	A[2][3]=10;
	A[3][6]=6;
	A[3][7]=1;
	A[4][5]=5;
	A[4][8]=6;
	A[5][8]=2;
	A[5][9]=1;
	A[5][6]=11;
	A[6][9]=3;
	A[6][10]=11;
	A[6][7]=2;
	A[7][10]=8;
	A[8][9]=4;
	A[9][10]=7;
	char Left,Right;
	int Weight;
	scanf("%c,%c,%d",&Left,&Right,&Weight);
	if(Left>Right)Swap(&Left,&Right);
	int L=Left-'A'+1;
	int R=Right-'A'+1;
	A[L][R]=Weight;							//�޸�һ���ߵ�Ȩֵ 
	int InTree[11]={0,0,0,0,0,0,0,0,0,0,0};//��Ϊ��ͨ�� 
	for(int i=1;i<10;i++)
	{
		int Min=100;
		int x;
		int y;
		for(int zuo=1;zuo<=9;zuo++)
		{
			for(int you=zuo;you<=10;you++)
			{
				if(A[zuo][you]!=0)
				{
					if(Min>A[zuo][you]&&Find(InTree,zuo)!=Find(InTree,you))//���ҵ�Ȩֵ��С����������û�ж���ͬһ��ͨ����ʱ 
					{
						
						Min=A[zuo][you];
						x=zuo;
						y=you;
					}
				}
			}
		}
		printf("%d,",Min);
		Union(InTree,Find(InTree,x),Find(InTree,y));//��ͨ���������� 
		//printf("zuo=%d\nyou=%d\nFindzuo=%d\nFindyou=%d\n",x,y,Find(InTree,x),Find(InTree,y));
	}
	return 0;
}
