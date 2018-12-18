#include <stdio.h>
#include <stdlib.h>


void ShellInsert(int *list, int length, int d)
{
    int temp;
    for(int i= d+1; i<length; i = i+d)
    {
        if(list[i] < list[i-d])
        {
            temp = list[i];
            int j;
            for(j = i-d; j>0 && temp<list[j];j=j-d)
            {
                list[j+d] = list[j];
            }
            list[j+d] = temp;
        }
    }
}

//希尔插入排序
void ShellSort(int *list, int length, int *d, int n)
{
    for(int i=0; i<n; i++)
    {
        ShellInsert(list, length, d[i]);    //根据d进行希尔插入排序
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
