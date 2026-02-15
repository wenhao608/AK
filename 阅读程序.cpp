#include <stdio.h>
int n;
int a[1000];
int f(int x)//f()函数的作用为求出传入参数的二进制情况下，1的个数
{
    int ret = 0;
    for(;x;x &= x-1)ret++;
    return ret;
}
int g(int x)
//g()函数为return x&-x 当一个偶数与它的负值向与时，结果是能被这个偶数整除的最大的//2的n次幂，当一个奇数与它的负值向与时结果一定是1
{
	return x & -x;
}
int main()
{
    scanf("%d",&n);
    for (int i=0; i < n; i++)scanf("%d",&a[i]);
    for (int i=0; i < n; i++)
       printf("%d %d %d",f(a[i]) + g(a[i]));
    printf("\n");
    return 0;
}

