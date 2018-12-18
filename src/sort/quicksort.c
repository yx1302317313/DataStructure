#include <stdio.h>

void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void QuickSort(int *list, int start, int end)
{
    if(start >= end)
    {
        return;
    }
    int low = start;
    int high = end;

    int temp = list[low];
    while(low < high)
    {
        //
        while(low < high && list[high] > temp)
        {
            high--;
        }

        Swap(&list[low], &list[high]);
        
        while(low < high && list[low] < temp)
        {
            low++;
        }
        
        Swap(&list[low], &list[high]);
    }
    //递归
    QuickSort(list,start, low-1);
    QuickSort(list,low+1, end);
}


int main(int argc, char const *argv[])
{
    
    return 0;
}
