#include <stdio.h>
#include <stdlib.h>


//简单插入排序
void InsertSort(int* list, int n)
{
    if(n <= 1)
    {
        return;
    }

    int temp = 0;

    for(int i=1; i<n; i++)
    {
        if(list[i] < list[i-1])
        {
            temp = list[i]; //暂存待排序对象
            int j;
            for(j = i-1; temp < list[j]; --j)
            {
                list[j+1] = list[j];    //向后移动
            }
            list[j+1] = temp; //插入在合适位置
        }
    }
}

//折半插入排序
void BiInsertSort(int* list, int n)
{
    if(n <= 1)
    {
        return;
    }

    int low, high, mid, temp;
    for(int i=1; i<n; i++)
    {
        if(list[i] < list[i-1])
        {
            //折半查找
            low = 0;
            high = i-1;
            temp = list[i];
            while(low <= high)
            {
                mid = (low + high)/2;
                if(temp < mid)
                {
                    high = mid -1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            //移动high后面元素
            int j;
            for(j=i-1; j>=high+1; --j)
            {
                list[j+1] = list[j];
            }
            list[high+1] = temp;
        }
    }
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
