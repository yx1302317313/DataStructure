#include <cstdio>
#include <cstdlib>
#include <stack>
#include <queue>

#define MAXSIZE 10

typedef int Elem;

typedef struct Node{

    Elem data;              //数据域
    struct Node *lch, *rch; //指针域

}BiTree;

BiTree* GoFarLeft(BiTree* T, std::stack<BiTree*> &s);
BiTree* GoFarRight(BiTree* T, std::stack<BiTree*> &s);
void VisitNode(BiTree *T);

void InOrderVisit(BiTree *T, void (*Visit)(BiTree*));
void PreOrderVisit(BiTree *T, void (*Visit)(BiTree*));
void NextOrderVisit(BiTree *T, void (*Visit)(BiTree*));

void InOrderVisit2(BiTree *T, void (*Visit)(BiTree*));
void PreOrderVisit2(BiTree *T, void (*Visit)(BiTree*));
void NextOrderVisit2(BiTree *T, void (*Visit)(BiTree*));


//递归构建二叉树
BiTree* CreatBinaryTree(BiTree* T, Elem* data, int index)
{
    if(index > MAXSIZE)
    {
        return nullptr;
    }
    BiTree *tree;


}

//中序递归遍历二叉树
void InOrderVisit(BiTree *T, void (*Visit)(BiTree*))
{
    if(T)
    {
        InOrderVisit(T->lch, Visit);
        (*Visit)(T);
        InOrderVisit(T->rch, Visit);
    }
}

//先序递归遍历二叉树
void PreOrderVisit(BiTree *T, void (*Visit)(BiTree*))
{
    if(T)
    {
        (*Visit)(T);
        InOrderVisit(T->lch, Visit);
        InOrderVisit(T->rch, Visit);
    }
}

//后序递归遍历二叉树
void NextOrderVisit(BiTree *T, void (*Visit)(BiTree*))
{
    if(T)
    {
        InOrderVisit(T->lch, Visit);
        InOrderVisit(T->rch, Visit);
        (*Visit)(T);
    }
}

//中序非递归遍历二叉树
void InOrderVisit2(BiTree *T, void (*Visit)(BiTree*))
{
    std::stack<BiTree*> s;  //创建栈

    BiTree* node = T;
    node = GoFarLeft(node, s);
    while(node)
    {
        Visit(node);
        if(node->rch)
        {
            node = GoFarLeft(node->rch, s);
        }
        else if(!s.empty())
        {
            node = s.top(); //得到栈顶
            s.pop();    //出栈
        }
        else
        {
            node = nullptr;
        }
    }
}

//先序非递归遍历二叉树
void PreOrderVisit2(BiTree *T, void (*Visit)(BiTree*))
{
    std::stack<BiTree*> s;  //创建栈

    BiTree* node = T;
    while(node != nullptr || !s.empty())
    {
        while(node)
        {
            Visit(node);    //根
            s.push(node);
            node = node->lch;   //左
        }
        if(!s.empty())
        {
            node = s.top();
            s.pop();
            node = node->rch;   //右
        }
    }
}


//后序非递归遍历二叉树
void NextOrderVisit2(BiTree *T, void (*Visit)(BiTree*))
{
    std::stack<BiTree*> s;  //创建栈

    BiTree* node = T;
    node = GoFarLeft(node, s);
    while(node)
    {
        if(node->rch)
        {
            node = GoFarLeft(node->rch, s);
        }

        if(node->rch)
        {
            node = GoFarLeft(node->rch, s);
        }
        else if(!s.empty())
        {
            node = s.top(); //得到栈顶
            s.pop();    //出栈
        }
        else
        {
            node = nullptr;
        }
    }
}

//层次遍历
void Levelvisit(BiTree* T, void (*Visit)(BiTree*))
{
    if(!T)
    {
        return;
    }

    std::queue<BiTree*> queue;

    BiTree* node = T;

    Visit(node);
    queue.push(node);
    while(!queue.empty())
    {
        node = queue.front();
        queue.pop();

        if(node->lch)
        {
            Visit(node->lch);
            queue.push(node->lch);
        }
        else if(node->rch)
        {
            Visit(node->rch);
            queue.push(node->rch);
        }
    }
}

//得到最左下节点
BiTree* GoFarLeft(BiTree* T, std::stack<BiTree*> &s)
{
    if(!T) 
    {
        return NULL;
    }
    
    BiTree *node = T;
    while(node->lch)
    {
        s.push(node);   //入栈
        node = node->lch;
    }
    return node;
}

//得到最右下节点
BiTree* GoFarRight(BiTree* T, std::stack<BiTree*> &s)
{
    if(!T) 
    {
        return NULL;
    }
    
    BiTree *node = T;
    while(node->rch)
    {
        s.push(node);   //入栈
        node = node->rch;
    }
    return node;
}

void VisitNode(BiTree *T)
{
    printf("%d ", T->data);
}

int main(int argc, char const *argv[])
{

    /* code */
    return 0;
}
