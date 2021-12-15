/*数据结构：KMP算法
查找一个主字符串里的子串，如查找'Hello world'里面有没有出现过'lo w'
平常的做法就是从第一个字母开始遍历，如果以该字母为起点的子串与要查找的子串不匹配，跳到下一个子串，继续从头开始比较
但是实际上，我们可能不需要子串从头开始比较。
如查找aaabaabaaab中的aab
第一次：
aaabaabaaab
aab
不匹配，但我们知道第一个和第二个都是a，下次子串往后挪一位比较的时候就可以不用比较第一位的a了
aaabaabaaab
 aab
这样会省很多时间。实际上针对要查找的子串每一位我们可以建立一个next数组，当该位查找失败时下一次子串查找起点在哪里
本题要求输入主串和要查找的子串，并根据子串建立next数组并输出，然后标记主串中哪些位置出现了被查找的子串
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Get_next(char T[], int next[])//建立next数组
{
	int j = 1; // postfix pointer
	int k = 0; //prefix pointer
	next[1] = 0;
	while (j <= strlen(T))
	{
		if (k == 0 || T[j] == T[k])
		{
			++j;
			++k;
			next[j] = k;
		}
		else
			k = next[k]; // k go back, then compare T[j] with T[ next[k] ]
	}					 //end while
	for (int i = 1; i <= strlen(T); i++)
		printf("%d,", next[i]);
	printf("\n");
	return;
}

int Index_KMP(char S[], char T[], int pos, int next[])//查找。S是主串，T是子串，pos是本次主串查找的起始位置
{
	int i = pos;
	int j = 1;
	while (i <= strlen(S+1) && j <= strlen(T+1))
	{
		if (j == 0 || S[i] == T[j])
		{
			++i;
			++j;
		}
		else
			j = next[j];
	}
	if (j > strlen(T+1))		  // find the match substring
		return i - strlen(T+1); // return index position 找到了，返回主串中子串的起始位置
	else
		return 0;//没找到
} // Index_KMP

int main()
{
	char MainString[201];
	scanf("%s", MainString+1);
	char PatternString[21];
	scanf("%s", PatternString+1);
	int Length = strlen(PatternString);
	int Next[21];
	Get_next(PatternString+1, Next);
	int result = Index_KMP(MainString, PatternString, 1, Next);
	if (result == 0)
		printf("-1\n");//主串没有找到子串
	else
		while (result != 0)
		{
			printf("%d\n", result);
			result = Index_KMP(MainString, PatternString, result + 1, Next);//前面的所有位置查完了，接下来继续查找后面的，result+1
		}
	return 0;
}
