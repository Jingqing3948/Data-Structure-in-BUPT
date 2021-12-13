/*���ݽṹ��ջ 
����׺���ʽת��Ϊ��׺���ʽ����������ʽ���
����������Դ���ʽ��ͬ���˶�����׺���ʽ��һĿ��Ȼ���������ֻ�ܴ����������룬�����׺���ʽ�������
���������׺���ʽ�����������ת��Ϊ��׺���ʽ�ٽ��м���
������ʹ���˼���ջ�Ļ���������д�Ļ��ǱȽ���ϸ*/ 
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 5000

typedef struct Stack
{
	char Array[MaxSize];						//������׺ת��Ϊ��׺ 
	int Top;
	double num[MaxSize];						//���ڼ��� 
	int TopInt;
} SnStack;

void InitStack(SnStack *S)						//ջ�ĳ�ʼ�� 
{
	S->Top = -1;
	S->TopInt = -1;
}

bool IsEmpty(SnStack S)							//�ж�ջ�Ƿ�Ϊ�� 
{
	return S.Top == -1;
}

bool Push(SnStack *S, char element)				//��ջ 
{
	S->Array[++S->Top] = element;
	return true;
}

void PushInt(SnStack *S, double element)		//���ڼ����׺���ʽ 
{
	S->num[++S->TopInt] = element;
	return;
}

char Top(SnStack S)								//��ȡջ��Ԫ�� 
{
	if (IsEmpty(S))
		return 'a';
	return S.Array[S.Top];
}

char Pop(SnStack *S)							//��ջ 
{
	if (IsEmpty(*S))
		return 'a';
	return S->Array[S->Top--];
}

double PopInt(SnStack *S)						//���ڼ����׺���ʽ
{
	return S->num[S->TopInt--];
}

int JudgePriority(char a, char b)				//�жϱ��ʽ���ȼ� 
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
	SnStack Cal;								//���ڼ����׺���ʽ
	char Result[MaxSize] = {'\0'};				//���ڴ洢�������׺���ʽ 
	int len = 0;
	InitStack(&S);
	char x;
	while (scanf("%c", &x) != EOF)
	{
		if (x >= '0' && x <= '9')
			Result[len++] = x;
		else
		{
			if ( x == '(')						//���������ţ���ջ 
				Push(&S, x);
			else
			{
				if (x == '+' || x == '-')		//����+-�ţ�������֮ǰ��ȫ����ջ��Ȼ��+-����ջ 
				{
					while (!IsEmpty(S) && Top(S) != '(')
					{
						Result[len++] = Pop(&S);
					}
					Push(&S, x);
				}
				else if (x == '*' || x == '/')	//����*/�ţ������һ������Ҳ��*��/����һֱ��ջ֪�����������Ż�+-��Ϊֹ��+-��ҲҪ��ջ�� 
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
				else if (x == ')')				//���������ţ����������ż��м�ķ���ȫ����ջ 
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
	while (!IsEmpty(S))							//������ջ�ǿգ�ջ��Ԫ��ȫ����ջ 
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
