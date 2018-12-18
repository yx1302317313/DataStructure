#include <iostream>

#define MAX_VERTEX 10

typedef int VerTex;
typedef int Elem;

//邻接矩阵
typedef struct ArcTable{

    VerTex ver; //顶点
    Elem info;  //信息
}ArcTable;

typedef struct 
{
    VerTex vertex[MAX_VERTEX];      //顶点表
    ArcTable arc[MAX_VERTEX][MAX_VERTEX];   //边表
    int ver_num, arc_num;
    int kind;

}Graph_Matrix;

//邻接表
typedef struct Arc{
    
    Elem info;
    struct Arc *next;

}ArcNode;

typedef struct 
{
    Elem data;
    ArcNode* firstarc;

}VerNode;

typedef struct 
{
    VerNode vertex[MAX_VERTEX];
    int ver_num, arc_num;
    int kind;

}Graph_Table;


//深度优先搜索
void DFS(Graph_Table G, int v)
{

}

//广度优先搜索
void BFS(Graph_Table G, int v)
{

}


int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}


