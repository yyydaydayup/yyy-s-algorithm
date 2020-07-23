/*******************************************
* 主题：算法学习
* 算法：快速排序（简单版）
*   策略：分治策略
*   输入：待排序数组，数组规模N
*   输出：排好序的数组
********************************************/

#include<stdio.h>
#include<stdlib.h>


/*****************函数声明*******************/
void Swap(int* a, int* b);
void QuickSort(int A[], int N);


/*****************主函数*******************/
int main()
{
    int a[]={5,0,7,6,4,8,3,1,2,9};
    for(int i=0;i<10;++i)
        printf("%d ", a[i]);

    QuickSort(a,10);//调用快速排序函数

    printf("\n");
    for(int i=0;i<10;++i)
        printf("%d ", a[i]);
    
    return 0;
}


/*****************函数定义区*******************/

void Swap(int* a, int* b)
{
    // 交换两个变量值的函数
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void QSort(int A[], int Left, int Right)
{
    if(Left >= Right)// 此处但用等于不对哦！因为2元素划分为1元素时会出现 Left>Right的情况。
        return;



    int Pivot,Low,High;

    Pivot = A[Left];//直接取第一个元素作为主元，简单而粗暴。
    Low=Left; //下面使用前置++，故让Low先指向主元。
    High=Right+1;//下面使用前置--,故让High先位于右边界的下一个。
    while (1)
    {
        while(A[++Low]<Pivot);
        while(A[--High]>Pivot);
        if(Low<High)
            Swap(&A[Low],&A[High]);
        else break;
    }
    Swap(&A[High], &A[Left]);
    /*
    * 主元归位
    * 因为一开始选择将主元藏在了左侧（第一个元素），所以用High指向的元素与主元进行交换。
    * （因为此时High指向的元素小于Low指向的元素，而升序时，小的应该放在左边，即主元刚刚所在的位置）
    * 如果一开始主元藏在了右边（选取最后一个元素），则主元与A[Low]交换。
    * 
    * 同样的，谁与主元交换，也决定了下面的分治中的参数选取。
    */
    QSort(A, Left, High-1);//递归解决左边
    QSort(A, High+1, Right);//递归解决右边
}

void QuickSort(int A[], int N)
{
    /*
    * 统一接口
    * 统一为 Sort(数组，元素个数) 的形式
    */
    QSort(A, 0, N-1);
}