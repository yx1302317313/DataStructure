#include <stdio.h>

void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void HeapAdjust(int *list, int n, int length)
{
    for(int i = 2*n+1; i<length; i = 2*n+1)
    {   
        int k = i;  //记录孩子节点中最大值的索引
        if(i+1 < length)    //存在右孩子
        {
            if(list[i] < list[i+1]) //找到孩子节点的最大值
            {
                k = i+1;
            }
        }
        if(list[n] < list[k])
        {
            Swap(&list[n], &list[k]);   //交换
            n = k;  //更新,接着向下调整
        }
        else
        {
            break;  //没有发生交换,不需要调整
        }
    }
}

void HeapSort(int *list, int length)
{
    //构建堆(从第一个非终端节点)
    for(int i = length/2 -1; i >= 0; i--)
    {
        HeapAdjust(list, i, length);
    }

    //堆排序
    for(int i=length; i>0 ;i--)
    {
        Swap(list[i], list[0]);
        HeapAdjust(list, 0, i-1); //调整堆
    }
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
