/*数据结构：栈
括号匹配是栈的一个常见应用。输入一串表达式，其中会包含()[]{}三种括号，检查括号是否匹配
()不匹配输出1,[]不匹配输出2,{}不匹配输出3, 
因为右括号总是和上一个左括号匹配 
我们需要做的是建立一个栈，每次左括号入栈，每次读到右括号时，刚才读到的最后一个左括号出栈与右括号进行匹配
不要忘记结尾，栈中可能会剩余一些尚未匹配的左括号，要将它们依次出栈*/ 
#include<stdio.h>
#define MaxLength 50

int main()
{
    char Stack[MaxLength]={0};//Stack是存储左括号的栈 
    int i=0;
    int wrong[3]={0};//wrong数组用来记录()[]{}三种括号是否出现过不匹配的情况 
    char x;
    while(scanf("%c",&x)!=EOF&&x!='\n')//EOF判断停止输入时结束输入，\n判断输入回车时结束输入 
    {
        if(x=='('||x=='['||x=='{')//左括号入栈 
        {
            Stack[i++]=x;
        }
        else if(x==')'||x==']'||x=='}')//右括号，则令第一个左括号出栈与右括号匹配 
        {
            if(i==0)
            {
                if(x==')')wrong[0]++;
                if(x==']')wrong[1]++;
                if(x=='}')wrong[2]++;
            }
            else if((Stack[i-1]=='('&&x==')')||(Stack[i-1]=='['&&x==']')||(Stack[i-1]=='{'&&x=='}')){i--;}
            else 
            {
                if(Stack[i-1]=='('||x==')')wrong[0]++;
                if(Stack[i-1]=='['||x==']')wrong[1]++;
                if(Stack[i-1]=='{'||x=='}')wrong[2]++;
            }
        }
    }
    while(i!=0)//输入结束但栈非空的情况。把栈中剩余的左括号依次出栈 
    {
        if(Stack[i-1]=='(')wrong[0]++;
        else if(Stack[i-1]=='[')wrong[1]++;
        else if(Stack[i-1]=='{')wrong[2]++;
        i--;
    }
    if(wrong[0]>0)
        printf("1,");
    if(wrong[1]>0)
        printf("2,");
    if(wrong[2]>0)
        printf("3,");
    printf("\n");
    return 0;
}

