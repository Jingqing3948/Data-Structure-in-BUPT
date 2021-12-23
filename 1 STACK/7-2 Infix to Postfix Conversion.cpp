/*数据结构：栈 
将中缀表达式转化为后缀表达式，并计算表达式结果
计算机与人脑处理方式不同，人对于中缀表达式更一目了然，而计算机只能从左往右输入，计算后缀表达式会更方便
因此输入中缀表达式，计算机会先转化为后缀表达式再进行计算
本例中使用了几个栈的基本操作，写的还是比较详细*/ 
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 5000

typedef struct Stack
{
	char Array[MaxSize];						//用于中缀转化为后缀 
	int Top;
	double num[MaxSize];						//用于计算 
	int TopInt;
} SnStack;

void InitStack(SnStack *S)						//栈的初始化 
{
	S->Top = -1;
	S->TopInt = -1;
}

bool IsEmpty(SnStack S)							//判断栈是否为空 
{
	return S.Top == -1;
}

bool Push(SnStack *S, char element)					//入栈 
{
	S->Array[++S->Top] = element;
	return true;
}

void PushInt(SnStack *S, double element)				//用于计算后缀表达式 
{
	S->num[++S->TopInt] = element;
	return;
}

char Top(SnStack S)							//读取栈顶元素 
{
	if (IsEmpty(S))
		return 'a';
	return S.Array[S.Top];
}

char Pop(SnStack *S)							//出栈 
{
	if (IsEmpty(*S))
		return 'a';
	return S->Array[S->Top--];
}

double PopInt(SnStack *S)						//用于计算后缀表达式
{
	return S->num[S->TopInt--];
}

int JudgePriority(char a, char b)					//判断表达式优先级 
{
	if (a == '+' && b == '+' || a == '+' && b == '-' || a == '-' && b == '-' || a == '-' && b == '+' || a == '*' && b == '*' || a == '*' && b == '/' || a == '/' && b == '*' || a == '/' && b == '/')
		return 0;
	else if (a == '+' && b == '*' || a == '+' && b == '/' || a == '-' && b == '*' || a == '-' && b == '/')
		return -1;
	else
		return 1;
}

int main()
{
	SnStack S;
	SnStack Cal;							//用于计算后缀表达式
	char Result[MaxSize] = {'\0'};					//用于存储并输出后缀表达式 
	int len = 0;
	InitStack(&S);
	char x;
	while (scanf("%c", &x) != EOF)
	{
		if (x >= '0' && x <= '9')
			Result[len++] = x;
		else
		{
			if ( x == '(')						//读到左括号：入栈 
				Push(&S, x);
			else
			{
				if (x == '+' || x == '-')			//读到+-号：左括号之前的全部出栈，然后+-号入栈 
				{
					while (!IsEmpty(S) && Top(S) != '(')
					{
						Result[len++] = Pop(&S);
					}
					Push(&S, x);
				}
				else if (x == '*' || x == '/')			//读到*/号：如果上一个符号也是*或/，则一直出栈直到碰到左括号或+-号为止（+-号也要出栈） 
				{
					if (Top(S) == '(')
					{}
					else if (JudgePriority(Top(S), x) == 0)
						while (!IsEmpty(S) && Top(S) != '(')
						{
							char temp = Pop(&S);
							Result[len++] = temp;
							if (temp == '+' || temp == '-')
								break;
						}
					Push(&S, x);
				}
				else if (x == ')')				//读到右括号：把左右括号及中间的符号全部出栈 
				{
					while (Top(S) != '(')
					{
						Result[len++] = Pop(&S);
					}
					Pop(&S);
				}
			}
		}
	}
	while (!IsEmpty(S))							//最后如果栈非空，栈中元素全部出栈 
	{
		Result[len++] = Pop(&S);
	}

	InitStack(&Cal);
	for (int i = 0; i < len; i++)
	{
		if (Result[i] >= '0' && Result[i] <= '9')
			PushInt(&Cal, Result[i] - '0');
		else if (Result[i] == '+')
		{
			double a = PopInt(&Cal);
			double b = PopInt(&Cal);
			double c = a + b;
			PushInt(&Cal, c);
		}
		else if (Result[i] == '-')
		{
			double a = PopInt(&Cal);
			double b = PopInt(&Cal);
			double c = b - a;
			PushInt(&Cal, c);
		}
		else if (Result[i] == '*')
		{
			double a = PopInt(&Cal);
			double b = PopInt(&Cal);
			double c = a * b;
			PushInt(&Cal, c);
		}
		else if (Result[i] == '/')
		{
			double a = PopInt(&Cal);
			double b = PopInt(&Cal);
			double c = b / a;
			PushInt(&Cal, c);
		}
	}
	printf("%.2lf\n", PopInt(&Cal));
	int i = 0;
	while (Result[i] != '\0')
	{
		printf("%c ", Result[i]);
		i++;
	}
	printf("\n");
	return 0;
}
