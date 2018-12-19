#include <iostream>

#define MAX_VERTEX 10
#define INT_MAX 100

typedef int VerTex;
typedef int Elem;

//邻接矩阵
typedef struct ArcTable{

    int adj; //关系, 权值
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
    
    VerTex vertex;
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


//邻接矩阵建立图(无向带权图)
void CreatGraphMatrix(Graph_Matrix *G)
{
    //初始化图的定点数, 弧数, 图的类型
    scanf("%d %d %d", &G->ver_num, &G->arc_num, &G->kind);
    
    //顶点集赋值
    for(int i=0; i<G->ver_num; i++)
    {
        scanf("%d", &G->vertex[i]);
    }

    //初始化图
    for(int i=0; i<G->ver_num; i++)
    {
        for(int j=0; j<G->ver_num; j++)
        {
            G->arc[i][j].adj = 0;
            G->arc[i][j].info = INT_MAX;
        }
    }

    int i, j, weight;
    //图赋值
    for(int k=0; k<G->arc_num; k++)
    {   
        scanf("%d %d %d",&i, &j, &weight);
        
        //无向图, 对称矩阵
        G->arc[i][j].adj = 1;   //关系
        G->arc[i][j].info = weight; //权值

        G->arc[j][i].adj = 1;
        G->arc[j][i].info = weight;
    }
}


//邻接表建立图(无向带权图)
void CreatGraphTable(Graph_Table *G)
{
    //初始化图的定点数, 弧数, 图的类型
    scanf("%d %d %d", &G->ver_num, &G->arc_num, &G->kind);
    //顶点集赋值
    for(int i=0; i<G->ver_num; i++)
    {
        scanf("%d", &G->vertex[i].data);
    }


    //边表赋值
    int i, j, weight;
    for(int k=0;k<G->arc_num; k++)
    {
        scanf("%d %d %d", &i, &j, &weight);
        ArcNode *node = (ArcNode*)malloc(sizeof(ArcNode));
        
        node->vertex = j;
        node->info = weight;
        //头插法
        node->next = G->vertex[i].firstarc;
        G->vertex[i].firstarc = node;
    }
}

void Visit()
{

}

//深度优先搜索
void DFS(Graph_Table *G, int *visited, int v)
{


}

void DFSTravel(Graph_Matrix *G)
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

