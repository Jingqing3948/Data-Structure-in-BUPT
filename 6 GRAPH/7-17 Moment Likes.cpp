/*数据结构：图的十字链表存储法
十字链表法
弧结点结构包含内容：弧尾顶点编号tailvex、弧头顶点编号headvex、弧头相同的下一条弧hlink、弧尾相同的下一条弧tlink（可能还有该弧的权值）
顶点结点结构包含内容：数据域data，该顶点作为弧头的第一条弧firstin，该顶点作为弧尾的第一条弧firstout
这里弧尾指的是箭头的末端，弧头指的是箭头指向的点
本题题目要求：
只有5个人，编号0~4
每个人对其关注的朋友按照序号进行排序，只对其关注的朋友中的顺序为奇数的朋友点赞，对偶数的朋友不点赞。要求计算某个人被点赞的情况
输入：先两两输入好友情况（a,b,a能看见b的朋友圈）然后输入一个人的序号
输出：输出所有给这个人点赞的人的序号，如果没有，输出-1*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct arc Arc;
typedef struct vertex Vertex;

struct arc//弧结构
{
	int Head;//指向的头
	int Tail;//指出的尾
	Arc HNext;//弧头相同的下一条弧
	Arc TNext;//弧尾相同的下一条弧
};

struct vertex//顶点结构
{
	int Node;//编号
	Arc FirstIn;//该顶点作为弧头的第一条弧
	Arc Firstout;//该顶点作为弧尾的第一条弧
};

typedef struct
{
	Vertex List[5];//存储所有顶点
} Graph;

void Print(Graph G,int target)
{
	return;
}

int main()
{
	Graph G;
	int target;
	scanf("%d", &target);
	Print(G, target);
	return 0;
}
