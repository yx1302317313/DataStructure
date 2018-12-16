#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void GetNext(char* pattern, int* next);
int IndexKMP(char* string, char* pattern, int pos);


int main(int argc, char const *argv[])
{
    char* string = "acabaabaabcacaabc";
    char* pattern = "abaabcac";
    int index = IndexKMP(string, pattern, 0);
    printf("position: %d\n", index);
    return 0;
}

//得到模式串的next数组
void GetNext(char* pattern, int* next)
{
    next[0] = -1;   //第一个元素next记为-1
    int i = 0, j=-1;
    while(i< strlen(pattern))
    {
        if(j == -1 || pattern[i] == pattern[j])
        {
            ++i;
            ++j;
            next[i] = j;
        }
        else
        {
            j = next[j];
        }
    }
    //for(int i=0; i<strlen(pattern); i++)
    //{
    //   printf("%d ", next[i]);
    //}
    //printf("\n");
}

//KMP匹配
int IndexKMP(char* string, char* pattern, int pos)
{
    if( pos<0 || pos > strlen(string) - strlen(pattern))
    {
        return -1;
    }

    int* next;
    next = (int*)malloc(sizeof(int) * strlen(pattern)); //模式串的next数组

    GetNext(pattern, next); //得到next数组

    int i = pos;
    int j = 0;
    while(i< strlen(string) && j < (int)strlen(pattern))
    {
        if(j == -1 || string[i] == pattern[j])
        {
            ++i; 
            ++j;
        }
        else
        {
            j = next[j];    //模式串右移至next[j]
        }
    }

    if(j >= strlen(pattern))    //匹配成功
    {
        return i - strlen(pattern);
    }
    else    //匹配失败
    {
        return -1;
    }
}
