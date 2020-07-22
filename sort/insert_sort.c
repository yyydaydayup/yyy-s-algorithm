#include <stdio.h>
#include <stdlib.h>

/*******************************************
* 主题：算法学习
* 算法：插入排序
*   策略：迭代策略
*   输入：待排序数组，数组规模N
*   输出：排好序的数组
* 
********************************************/

/*****************函数声明*******************/
void InsertSort(int array[], int N);

/*****************主函数*******************/
int main()
{
    int a[] = {7, 4, 6, 2, 1, 8, 5, 0, 9, 3};
    //打印数组
    for (int i = 0; i < 10; ++i)
        printf("%d ", a[i]);
    printf("\n");

    InsertSort(a, 10);//调用插入排序

    //打印数组
    for (int i = 0; i < 10; i++)
        printf("%d ", a[i]);

    return 0;
}

/*****************函数定义区*******************/
void InsertSort(int array[], int N)
{
    int temp;
    for (int pos = 1; pos < N; ++pos)// 这里pos初值设为1便好，0号默认有序。
    {
        temp = array[pos];
        int i;
        for (i = pos; i > 0 && temp < array[i - 1]; --i)
            array[i] = array[i - 1];
        array[i] = temp;
    }
}