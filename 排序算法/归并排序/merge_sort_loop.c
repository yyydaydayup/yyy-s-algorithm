#include <stdio.h>
#include <stdlib.h>
#define NUM 11

typedef int ElementType;

void Merge_pass(ElementType A[], ElementType TmpA[], int N, int length);
void Merge_Sort(ElementType A[], int N);
void Merge(ElementType A[], ElementType TmpA[], int L, int R, int RightEnd);


int main()
{
    // 生成测试数据并打印
    int a[NUM] = {100, 45, 65, 34, 87, 89, 57, 230, 56, 59,78};
    printf("before sort:\n");
    for (int i = 0; i < NUM; ++i)
        printf("%d ", a[i]);

    //调用封装好的【归并排序】算法
    Merge_Sort(a, NUM); 

    //打印排序后的结果，与排序前比较。
    printf("\n\nafter sort:\n");
    for (int i = 0; i < NUM; ++i) 
        printf("%d ", a[i]);
    return 0;
}

/* 归并排序 - 循环实现 */
/* 这里Merge函数在递归版本中给出 */

/* length = 当前有序子列的长度*/
void Merge_pass(ElementType A[], ElementType TmpA[], int N, int length)
{ /* 两两归并相邻有序子列 */
    int i, j;

    for (i = 0; i < N - 2 * length; i += 2 * length)
        Merge(A, TmpA, i, i + length, i + 2 * length - 1);
    if (i + length < N) /* 归并最后2个子列*/
        Merge(A, TmpA, i, i + length, N - 1);
    else /* 最后只剩1个子列*/
        for (j = i; j < N; j++)
            TmpA[j] = A[j];
}

void Merge_Sort(ElementType A[], int N)
{
    int length;
    ElementType *TmpA;

    length = 1; /* 初始化子序列长度*/
    TmpA = malloc(N * sizeof(ElementType));
    if (TmpA != NULL)
    {
        while (length < N)
        {
            Merge_pass(A, TmpA, N, length);
            length *= 2;
            Merge_pass(TmpA, A, N, length);
            length *= 2;
        }
        free(TmpA);
    }
    else
        printf("空间不足");
}

/* L = 左边起始位置, R = 右边起始位置, RightEnd = 右边终点位置*/
void Merge(ElementType A[], ElementType TmpA[], int L, int R, int RightEnd)
{ /* 将有序的A[L]~A[R-1]和A[R]~A[RightEnd]归并成一个有序序列 */
    int LeftEnd, NumElements, Tmp;
    int i;

    LeftEnd = R - 1; /* 左边终点位置 */
    Tmp = L;         /* 有序序列的起始位置 */
    NumElements = RightEnd - L + 1;

    while (L <= LeftEnd && R <= RightEnd)
    {
        if (A[L] <= A[R])
            TmpA[Tmp++] = A[L++]; /* 将左边元素复制到TmpA */
        else
            TmpA[Tmp++] = A[R++]; /* 将右边元素复制到TmpA */
    }

    while (L <= LeftEnd)
        TmpA[Tmp++] = A[L++]; /* 直接复制左边剩下的 */
    while (R <= RightEnd)
        TmpA[Tmp++] = A[R++]; /* 直接复制右边剩下的 */

    for (i = 0; i < NumElements; i++, RightEnd--)
        A[RightEnd] = TmpA[RightEnd]; /* 将有序的TmpA[]复制回A[] */
}
