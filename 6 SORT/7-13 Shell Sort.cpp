/*数据结构：希尔排序
每次我们以间隔为d选出几组数据，进行排序输入了n个数，一开始分组情况为：
1          n/2+1
 2              n/2+2
  3                 n/2+3
……
然后分别对每个子组进行排序
然后d/2，再重复上述操作
逐渐缩小至d==1*/
#include<stdio.h>
#define MaxSize 20
int main()
{
    int Data[MaxSize];
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d,",&Data[i]);
    }
    for(int d=n/2;d>=1;d/=2)
    {
        for(int k=1;k<=n-d;k++)//进行插入排序
        {
            if(Data[k]<Data[k+d])
            {
                Data[0]=Data[k+d];//0位相当于temp，暂时存储要移动的数据
                int jud=k;
                for(;jud>=1&&Data[0]>Data[jud];jud-=d){
                    Data[jud+d]=Data[jud];
                }
                Data[jud+d]=Data[0];
            }
        }
        for(int i=1;i<=n;i++)
        {
            printf("%d,",Data[i]);
        }
        printf("\n");
    }
    return 0;
}
