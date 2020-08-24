#include <stdio.h>
#include <stdlib.h>
#define NUM 10
/*******************************************
* 主题：算法学习
* 算法：归并排序
*   策略：分治策略
*   输入：待排序数组，数组规模N
*   输出：排好序的数组
* 
********************************************/

//****************函数声明******************
void MergeSortRecursive(int arr[], int temp[], int start, int end);
void MergeSort(int arr[], int N);

//*****************主程序*******************
int main()
{
    // 生成测试数据并打印
    int a[NUM] = {100, 45, 65, 34, 87, 89, 57, 230, 56, 59};
    printf("before sort:\n");
    for (int i = 0; i < NUM; ++i)
        printf("%d ", a[i]);

    //调用封装好的【归并排序】算法
    MergeSort(a, NUM); 

    //打印排序后的结果，与排序前比较。
    printf("\n\nafter sort:\n");
    for (int i = 0; i < NUM; ++i) 
        printf("%d ", a[i]);
    return 0;
}

//******************函数区*****************

void Merge()
{

}
void MergeSortRecursive(int arr[], int temp[], int start, int end)
{
    if (start >= end)//递归终止条件
        return; // start==end 时表示只有一个元素，此时数组是有序的,故终止条件包含等号。

    int mid = start + ((end-start)>>1);//+、-的优先级大于<<、>>
    /******************************************************************************
    * 此句等价于 int mid = start + (end - start)/2; 采用位移代替除法，效率会更高。
    * 进一步等价于 int mid = (start + end) / 2;  为避免求和可能导致的溢出，故不用改方案。
    *******************************************************************************/
    int start1 = start, end1 = mid;
    int start2 = mid + 1, end2 = end;

    MergeSortRecursive(arr, temp, start1, end1); //递归处理左子序列
    MergeSortRecursive(arr, temp, start2, end2); //递归处理右子序列

    int k = start;
    while (start1 <= end1 && start2 <= end2)
        temp[k++] = arr[start1] <= arr[start2] ? arr[start1++] : arr[start2++]; //取出小的
    /****************************************************************************************************
    * （1）上面的比较条件是 <= ，这样在合并时就会把处在前面的序列的元素保存在结果序列的前面，此时排序时稳定的。
    * （2）如果把 <= 改为 < , 排序便不稳定了。
    * 我们知道，在各大排序算法对比分析时，归并排序属于“稳定排序”，所以我们可以得出结论，评判一个排序算法是否
    * 稳定，并不是说它在任何情况下都稳定，而是说“能够”做到稳定。
    *****************************************************************************************************/
    

    while (start1 <= end1)
        temp[k++] = arr[start1++];
    while (start2 <= end2)
        temp[k++] = arr[start2++];

    for (k = start; k <= end; k++) //将放在临时数组中排好序的数据复制回原数组。
        arr[k] = temp[k];
}

void MergeSort(int arr[], int N)
{
    //将MergeSortRecursive封装成(数组，规模)的统一排序接口。
    int temp[N];
    MergeSortRecursive(arr, temp, 0, N - 1);
}