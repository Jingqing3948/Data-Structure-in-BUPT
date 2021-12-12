/*数据结构：二叉查找树
算是很简单的树，没有高度要求，比根节点小的存在左子树，比根节点大的存在右子树
输出第n层level上的所有结点，因此树的结构中要存level结点信息
也可以不存，在print函数中递归不断改变参数Level的值应该也可以*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct binarytree
{
	int Element;
	int Level;
	struct binarytree *Leftchild, *Rightchild;
} binarytree, BinaryTree, *PTree, *PTreeNode;

PTree Insertion(PTree T, PTreeNode TN, int Level)
{
	if (T == NULL)
	{
		TN->Level = Level;
		T = TN;
	}
	else
	{
		if (TN->Element < T->Element)
			T->Leftchild = Insertion(T->Leftchild, TN, Level + 1);
		else if (TN->Element > T->Element)
			T->Rightchild = Insertion(T->Rightchild, TN, Level + 1);
	}
	return T;
}

bool Print(PTree T, int Level)//寻找并输出第level层的节点 
{
	if (T == NULL)
		return 0;
	else if (T->Level < Level)
	{
		int jud1 = Print(T->Leftchild, Level);
		int jud2 = Print(T->Rightchild, Level);
		if (jud1 || jud2)
		{
			return 1;
		}
		else
			return 0;
	}
	else if (T->Level == Level)
	{
		printf("%d,", T->Element);
		return 1;
	}
}

int main()
{
	int n, Data;
	PTree T = NULL;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d,", &Data);
		PTreeNode TN = (PTreeNode)malloc(sizeof(binarytree));
		TN->Element = Data;
		TN->Leftchild = NULL;
		TN->Rightchild = NULL;
		T = Insertion(T, TN, 1);
	}
	int outputlayer;
	scanf("%d", &outputlayer);
	if (Print(T, outputlayer) == 0)
		printf("-1");
	printf("\n");
	return 0;
}
