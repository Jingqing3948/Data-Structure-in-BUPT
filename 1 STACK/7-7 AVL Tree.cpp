/*数据结构：AVL树
二叉查找树固然方便，但是有可能树只往一边长，那样的话相比链表就发挥不出树的查找优势了
所以树要尽可能横向延伸
怎么实现？当左右子树高度差等于2时进行一次旋转
使得左右子树高度差始终保持在0或1*/
#include <stdio.h>
#include <stdlib.h>

typedef struct treenode
{
	int Element;
	struct treenode *LeftChild, *RightChild;
} * Tree, *TreeNode;

int Max(int a, int b)
{
	if (a >= b)
		return a;
	else
		return b;
}

int Height(Tree T)
{
	if (T == NULL)
		return -1;
	else
		return Max(Height(T->LeftChild), Height(T->RightChild)) + 1;
}

Tree SingleRotatewithLeft(Tree T)			//当对左孩子的左子树插入节点后，高度差左子树-右子树=2
{
	TreeNode LeftTree = T->LeftChild;
	T->LeftChild = LeftTree->RightChild;
	LeftTree->RightChild = T;
	return LeftTree;
}

Tree SingleRotatewithRight(Tree T) 			//当对右孩子的右子树插入节点后，高度差右子树-左子树=2
{
	TreeNode RightTree = T->RightChild;
	T->RightChild = RightTree->LeftChild;
	RightTree->LeftChild = T;
	return RightTree;
}

Tree DoubleRotatewithLeft(Tree T) 			//当对左孩子的右子树插入节点后，高度差左子树-右子树=2
{
	T->LeftChild = SingleRotatewithRight(T->LeftChild);
	return SingleRotatewithLeft(T);
}

Tree DoubleRotatewithRight(Tree T) 			//当对右孩子的左子树插入节点后，高度差右子树-左子树=2
{
	T->RightChild = SingleRotatewithLeft(T->RightChild);
	return SingleRotatewithRight(T);
}

Tree Insert(Tree T, TreeNode TN)
{
	if (T == NULL)
		T = TN;
	else
	{
		if (TN->Element > T->Element)
		{
			T->RightChild = Insert(T->RightChild, TN);
			if (Height(T->RightChild) - Height(T->LeftChild) == 2)
			{
				if (TN->Element > T->RightChild->Element)
					T = SingleRotatewithRight(T);
				else
					T = DoubleRotatewithRight(T);
			}
		}
		else if (TN->Element < T->Element)
		{
			T->LeftChild = Insert(T->LeftChild, TN);
			if (Height(T->LeftChild) - Height(T->RightChild) == 2)
			{
				if (TN->Element < T->LeftChild->Element)
					T = SingleRotatewithLeft(T);
				else
					T = DoubleRotatewithLeft(T);
			}
		}
	}
	return T;
}

void PrintPreOrder(Tree T)
{
	if (T != NULL)
		printf("%d,", T->Element);
	else
		return;
	if (T->LeftChild != NULL)
		PrintPreOrder(T->LeftChild);
	if (T->RightChild != NULL)
		PrintPreOrder(T->RightChild);
	return;
}

int main()
{
	Tree T = NULL;
	int Data;
	while (scanf("%d,", &Data) != EOF)
	{
		TreeNode TN = (TreeNode)malloc(sizeof(struct treenode));
		TN->Element = Data;
		TN->LeftChild = NULL;
		TN->RightChild = NULL;
		T = Insert(T, TN);
	}
	PrintPreOrder(T);
	printf("\n");
	return 0;
}