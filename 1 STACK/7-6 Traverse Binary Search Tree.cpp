/*数据结构：二叉查找树
本题要求根据输入序列建立二叉查找树，并以前序输出(preorder)
上一题其实已经解决二叉查找树的问题，这一题只在于前序输出，即先输出本节点，然后递归输出左子树、右子树*/
#include <stdio.h>
#include <stdlib.h>

typedef struct binarytree
{
	int Element;
	struct binarytree *Leftchild, *Rightchild;
} BinaryTree, *PTree, *PTreeNode;

PTree Insertion(PTree T, PTreeNode TN)
{
	if (T == NULL)
	{
		T = TN;
	}
	else
	{
		if (TN->Element < T->Element)
			T->Leftchild = Insertion(T->Leftchild, TN);
		else if (TN->Element > T->Element)
			T->Rightchild = Insertion(T->Rightchild, TN);
	}
	return T;
}

void PrintPreOrder(PTree T)
{
	if (T != NULL)
		printf("%d,", T->Element);		//输出本节点
	if (T->Leftchild != NULL)
		PrintPreOrder(T->Leftchild);	//输出左子树
	if (T->Rightchild != NULL)
		PrintPreOrder(T->Rightchild);	//输出右子树
}

int main()
{
	PTree T = NULL;
	int Data;
	while (scanf("%d,", &Data) != EOF)
	{
		PTreeNode TN = (PTreeNode)malloc(sizeof(BinaryTree));
		TN->Element = Data;
		TN->Leftchild = NULL;
		TN->Rightchild = NULL;
		T = Insertion(T, TN);
	}
	PrintPreOrder(T);
	printf("\n");
	return 0;
}