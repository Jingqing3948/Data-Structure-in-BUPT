/*数据结构：二项队列
当我们合并两个堆的时候，直接令根节点较大的堆的根节点仍然作为新堆的根节点，根节点较小的堆的根节点作为新堆的子树
问题是一直这样合并下去，树的平衡性会降低（一直往一边插入）
有三种典型的解决办法：左式堆 斜堆 二项队列
左式堆：一直保证树的左子树高（如果右子树高于左子树则旋转）插入的时候一直插入到右子树
斜堆：每次插入都旋转，根据概率树往一边生长的概率极小
二项队列：直接建立一个森林，插入的时候只会影响一部分树。缺点在于查找的时候效率会稍微降低一些，我们有很多棵树，很多个根节点
树的节点数分别是1 2 4 8 16……
当森林中存在两个节点数为n-1的树时，合并他们并进位到第n位（类似二进制）*/
#include<stdio.h> 
#include<stdlib.h>
#define MaxSize 100

typedef struct tree{				//树的结构，由于是堆转化而来还要合并，因此采用孩子兄弟表示法
	int Element;
	struct tree *NextSibling;
	struct tree *FirstChild;
}*Tree;

typedef struct collection{			//森林的结构
	int Size;
	Tree TheTrees[MaxSize];
}*Queue;

Tree CombineTrees(Tree T1,Tree T2)	//合并两棵树的函数
{
	if(T1->Element>T2->Element)return CombineTrees(T2,T1);
	Tree p=T1->FirstChild;
	if(p==NULL)T1->FirstChild=T2;
	else
	{
		while(p->NextSibling!=NULL)p=p->NextSibling;
		p->NextSibling=T2;
	}
	return T1;
}

Queue Merge(Queue Q1,Queue Q2)		//合并两森林的函数。实际上第二个森林里只有一棵树，我们要新合并到旧森林的那棵树
{
	
	Tree T1,T2,Carry=NULL;
	 Q1->Size+=Q2->Size;
	 for(int i=0,j=1;j<=Q1->Size;i++,j*=2)
	 {
	 	T1=Q1->TheTrees[i];			//每次合并森林中第i棵树（可能为空）
	 	T2=Q2->TheTrees[i];
	 	switch(4*!!Carry+2*!!T1+!!T2)//绝妙的地方，这里是重点
	 	{
			/*上面的算式意思就是判断T1,T2,Carry有哪些不为空，用二进制来表示
			 Carry是低一位可能进位上来的树
			 000:0，代表三者都为空，不用进行任何操作，Q1->TheTrees[i]仍然为空*/
			case 0:
				break;
			/*001 : 1，代表T2不为空，把T2放进Q1->TheTrees[i]*/
	 		case 1:
			 	Q1->TheTrees[i]=Q2->TheTrees[i];
	 			Q2->TheTrees[i]=NULL;
	 			break;
			/*010 : 2，代表T1不为空，Q1->TheTrees[i] 本来就放好了而且是唯一非空树，不用进行任何操作*/
			case 2:
				break;
			/*011 : 3，代表T1，T2不为空，合并两者之后的子树应该进位到上一位*/
	 		case 3:
	 			Carry=CombineTrees(T1,T2);
	 			Q1->TheTrees[i]=NULL;
	 			Q2->TheTrees[i]=NULL;
	 			break;
			/*100 : 4，代表只有Carry不为空，类似情况1*/
	 		case 4:
	 			Q1->TheTrees[i]=Carry;
	 			Carry=NULL;
	 			break;
			/*101 ：5，代表Carry和T2不为空，类似情况3*/
	 		case 5:
	 			Carry=CombineTrees(Carry,T2);
	 			Q2->TheTrees[i]=NULL;
	 			break;
			/*110 : 6，代表Carry和T1不为空，类似情况3*/
	 		case 6:
	 			Carry=CombineTrees(Carry,T1);
	 			Q1->TheTrees[i]=NULL;
	 			break;
			/*111 : 7，代表Carry，T1，T2都不为空，这种算法优先把刚进位的Carry留在此处，合并T1，T2进位到上一位*/
	 		case 7:
	 			Q1->TheTrees[i]=Carry;
	 			Carry=CombineTrees(T1,T2);
	 			Q2->TheTrees[i]=NULL;
	 			break;
		}
	 }
	 return Q1;
	 
}

void Print(Tree T) //遍历输出
{
	if(T==NULL)
    {
        return;
    }
	printf("%d,",T->Element);
	Print(T->NextSibling);
	Print(T->FirstChild);
	
}

int main()
{	
	Queue Q1=(Queue)malloc(sizeof(struct collection));
	Q1->Size=0;
	Q1->TheTrees[0]=NULL;
	Queue Q2=(Queue)malloc(sizeof(struct collection));
	Q2->Size=1;
	Q2->TheTrees[0]=NULL;
	char n;
	int data=0;
	while(scanf("%c",&n)&&n!='\n')				//这里是为了应对题目的输入，输入数字不只有个位数，而且数字间有逗号，结尾无逗号
	{
												//形如1,2,33,4
		if(n!=',')
		{
			data=data*10+(n-'0');
		}
		
		else
		{			
			Q2->TheTrees[0]=(Tree)malloc(sizeof(struct tree));
			Q2->TheTrees[0]->Element=data;
			Q2->TheTrees[0]->FirstChild=NULL;
			Q2->TheTrees[0]->NextSibling=NULL;
			Q1=Merge(Q1,Q2);					//每次把新结点放入刚建立的森林Q2,并合并到森林Q1中
			Q2->TheTrees[0]=NULL;
			data=0;
		}
	}
	int n1;
	scanf("%d",&n1);
    if(Q1->TheTrees[n1]==NULL)printf("0,");		//如果没输入
    else	Print(Q1->TheTrees[n1]);
	return 0;
}