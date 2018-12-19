#include <stdio.h>

//归并
void Merge(int *list, int start, int mid, int end, int *temp)
{
    int i = start;
    int j = mid;
    int k = start;

    //归并
    while(i <= mid && j <= end)
    {
        if(list[i] < list[j])
        {
            temp[k++] = list[i++];
        }
        else
        {
            temp[k++] = list[j++];
        }
    }

    //剩余元素全部复制
    while(i <= mid)
    {
        temp[k++] = list[i++];
    }

    while(j <= end)
    {
        temp[k++] = list[j++];
    }

    k = start;
    while(k <= end)
    {
        list[k++] = temp[k++];  //拷贝回list
    }
}

//归并排序,需要一个辅助数组
void MergeSort(int *list, int length, int start, int end, int *temp)
{
    if(start >= end)
    {
        return;
    }

    int mid = (start, end)/2;
    MergeSort(list, length, start, mid, temp);
    MergeSort(list, length, mid+1, end, temp);
    Merge(list, start, mid, end, temp);
}


int main(int argc, char const *argv[])
{
    
    return 0;
}
