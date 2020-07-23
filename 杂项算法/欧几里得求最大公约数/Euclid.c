#include <stdio.h>
#include <stdlib.h>

/*******************************************
* 主题：算法学习
* 算法：欧几里得法求最大公约数
*   策略：迭代策略
*   输入：两个非负整数a,b,其中a和b不全为0
*   输出：a和b的最大公约数
* 
********************************************/

/******************函数声明******************/
int Euclid(int a, int b);

/******************主函数******************/

int main()
{
    int a, b;
    printf("Input two numbers(>=0):\n");
    scanf("%d%d", &a, &b);
    printf("gcd is %d.\n", Euclid(a, b));
    return 0;
}

/*****************函数定义区*****************/
int Euclid(int a, int b)
{
    int r = a % b;
    while (r)
    {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}