#include <stdio.h>
#include <stdlib.h>

/*******************************************
* 主题：算法学习
* 算法：Hanoi问题
*   策略：分治策略
*   输入：三个柱子，待移动金属片数量
*   输出：打印移动路径
* 
********************************************/


/*******************函数声明*****************/
void move(char from, char to, int num);
void Hanoi(char src, char mid, char dest, int num);

/*******************主函数*****************/
int main()
{
    Hanoi('A', 'B', 'C', 3);
    return 0;
}

/*******************函数定义区*****************/
void Hanoi(char src, char mid, char dest, int num)
{
    /*
    *   src: 初始柱子
    *   mid：中间过渡的柱子
    *   dest：目标柱子
    *   num：一共要移动的金属片的个数
    */
    
    if (num == 1)
        move(src, dest, num);
    else
    {
        Hanoi(src, dest, mid, num - 1);//先把n-1个金属片从原柱子经过目标柱子移动到中间柱子
        move(src, dest,num);//再把第n个金属片（最下面最大的那个）从原柱子直接移动到目标柱子
        Hanoi(mid, src, dest, num - 1);//最后把中间柱子上的n-1个金属片经过原柱子移动到目标柱子
    }
}

void move(char from, char to, int num)
{
    /*
    *   from：起始点
    *   to：终点
    *   num：当前移动的金属片的编号
    */
    printf("[%d]: [%c]->[%c]\n",num, from, to);
}