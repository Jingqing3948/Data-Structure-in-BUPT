/*数据结构：散列表
处理冲突的方法——平方定址法
主要有两种处理冲突的办法，链接法是对数组的每一个单元都是一个链表，比较权值相同的都穿在那个链表中
平方定址法是如果该数组位已经有元素了，那么把他放在+1*1的数组位上；如果那一位也有元素了，就放在+2*2的数组位上……以此类推
我学到的另一种方法是依次比较+1,-1,+4,-4,+9,-9……根据具体不同老师或不同题型进行调整
一般比较到数组总长/2的时候就不继续比较了，因为已经超出数组长度了*/
#include <stdio.h>
int main()
{
	long long Box[10] = {0};
	char comma;
	long long Data;
	do
	{
		scanf("%lld", &Data);
		int predict = Data % 10;
		long long i = 0;
		int cnt = 1;
		while (Box[(predict + i * i) % 10] != 0 && cnt <= 5)//该位冲突
		{
			i++;
			cnt++;
		}
		if (cnt <= 5) //跳出循环，找到了不冲突的一位
			Box[(predict + i * i) % 10] = Data; 
	} while (scanf("%c", &comma) != EOF && comma == ',');
	for (int i = 0; i < 9; i++)
		printf("%lld,", Box[i]);
	printf("%lld\n", Box[9]);
	return 0;
}
