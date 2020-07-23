/*******************************************
* 主题：算法学习
* 算法：快速排序（实战版）
*   策略：分治策略
*   输入：待排序数组，数组规模N
*   输出：排好序的数组
********************************************/

#include<stdio.h>
#include<stdlib.h>

/*****************函数声明*******************/
void Swap(int* a, int* b);
int Median3(int A[], int Left, int Right);
void QSort(int A[], int Left, int Right);
void QuickSort(int A[], int N);
void InsertSort(int array[], int N);

/*****************主函数*******************/

int Cutoff=5;
/*
* 当元素数量小于该值时，直接采用简单排序来避免递归。
* 该变量受到取主元函数的约束，下界为2（详见Median3()函数）。
*/


int main()
{
    int a[]={4,8,3,1,2,9,0,7,6,5};
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

int Median3(int A[], int Left, int Right)
{
    /*
    * 该函数为“选主元”函数
    * 取左、中、右三个位置的数值然后排序，将中位数当做主元
    * 
    * 约束：
    *       1.要求A中至少有2个元素，因为用到了A[Right-1]。
    *       2.所以若用该种方法，全局变量Cutoff的的下界是2。
    */
    int Center = (Left+Right)/2;
    if(A[Left]>A[Center])
        Swap(&A[Left], &A[Center]);
    if(A[Left]>A[Right])
        Swap(&A[Left], &A[Right]);
    if(A[Center]>A[Right])
        Swap(&A[Center], &A[Right]);
    /*
    * 到此为止， A[Left] <= A[Center] <= A[Right]
    */
    Swap(&A[Center],&A[Right-1]);
    /*
    * 把pivot藏到右边
    * 这样就只需考虑 A[Left+1]...A[Right-2]了
    */
    return A[Right-1];
}


void QSort(int A[], int Left, int Right)
{
    if(Cutoff <= Right-Left){
        int Pivot, Low, High;
        Pivot = Median3(A, Left, Right);//选取主元并隐藏到Right-1的位置
        Low = Left; //此时Low指向最左边元素
        High=Right-1;//此时High指向主元隐藏位置
        while (1)
        { /*将序列中比基准小的移到基准左边，大的移到右边*/
            while(A[++Low]<Pivot);
            while(A[--High]>Pivot);
            /*
            * 此处用前置的++和--，有3处约束
            * 1.Low和High的初值分别是Left和Right-1
            * 2.下面交换时交换的是A[Low]和A[High]。
            * 3.下面的终止条件是Low >= High。
            */

            if(Low<High)
                Swap(&A[Low], &A[High]);
            else break;
        }
        Swap(&A[Low], &A[Right-1]);
        /*
        * 主元归位
        * 因为一开始选择将主元藏在了右侧，所以用Low指向的元素与主元进行交换。
        * （因为此时Low指向的元素大于High指向的元素，而升序时，大的应该放在右边，即主元刚刚所在的位置）
        * 如果一开始主元藏在了左边，则主元与A[High]交换。
        * 
        * 同样的，谁与主元交换，也决定了下面的分治中的参数选取。
        */
        QSort(A,Left, Low-1);//递归解决左边
        QSort(A,Low+1, Right);//递归解决右边
    }else{
        /*
        * 当元素数目不多时，用递归反而浪费时间，直接
        */
        InsertSort(A+Left, Right-Left+1);//充分利用了C语言特性：数组名=首地址。
    }
        
}

void QuickSort(int A[], int N)
{
    /*
    * 统一接口
    * 统一为 Sort(数组，元素个数) 的形式
    */
    QSort(A, 0, N-1);
}


void InsertSort(int array[], int N)
{
    /*
    * 插入排序
    */
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