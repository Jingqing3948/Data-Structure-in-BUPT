/*数据结构：最小生成树
图的生成树：最小连通子图
连通图：图中所有顶点都联通
也就是说图的生成树是用最少的边把所有顶点联通起来
而图的最小生成树则是边权值最小的生成树
Prim算法：首先选择一个顶点作为树的根节点，然后每次把代价最小的新结点加入树
Kruskal算法：在图中找到权值最小的边，使得边两头的两个结点联通（如果已经联通了就忽略）直到所有顶点都加入连通图
本题我采用的是Kruskal算法，再次使用了一些不相交集的知识
题目要求：首先图已经给好了。顶点包括A~J，我用数组下标中的1~10表示
然后相连接的边的权值也已给出
输入两个顶点，以及一个权值，修改该图中的一条边的权值（如A,B,1）
然后从小到大输出建立的最小生成树中的边的权值（这也是我选择Kruskal算法的原因之一）*/
#include<stdio.h>

void Union(int S[],int root1,int root2)//合并两个联通集 
{
	
	S[root2]=root1;
	return;
}

int Find(int S[],int root)//查找root顶点所属的联通集 
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
	A[L][R]=Weight;							//修改一条边的权值 
	int InTree[11]={0,0,0,0,0,0,0,0,0,0,0};//作为联通集 
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
					if(Min>A[zuo][you]&&Find(InTree,zuo)!=Find(InTree,you))//若找到权值最小，且两顶点没有都在同一连通集中时 
					{
						
						Min=A[zuo][you];
						x=zuo;
						y=you;
					}
				}
			}
		}
		printf("%d,",Min);
		Union(InTree,Find(InTree,x),Find(InTree,y));//连通这两个顶点 
		//printf("zuo=%d\nyou=%d\nFindzuo=%d\nFindyou=%d\n",x,y,Find(InTree,x),Find(InTree,y));
	}
	return 0;
}
