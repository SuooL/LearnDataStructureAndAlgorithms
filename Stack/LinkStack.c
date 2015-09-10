#include "stdio.h"
#include "stdlib.h"

#include "math.h"
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* 存储空间初始分配量 */

typedef int Status;
typedef int SElemType;

/*
 * 链栈结构定义
 * 链栈节点是StackNode类型结构
 * 链栈是LinkStack
 */
typedef struct StackNode
{
    SElemType data;
    struct StackNode *next;
}StackNode,*LinkStackPtr;

typedef struct
{
    LinkStackPtr top;
    int count;       // 长度
}LinkStack;

// 访问节点数据
Status visit(SElemType c)
{
    printf("%d ",c);
    return OK;
}

/*
 * 初始化一个空的链栈
 *
 */

Status InitStack(LinkStack *S)
{
    S->top = (LinkStackPtr)malloc(sizeof(StackNode));
    if(!S->top)
        return ERROR;
    S->top = NULL;
    S->count = 0;
    return OK;
}

/* 把S置为空栈 */
Status ClearStack(LinkStack *S)
{
    LinkStackPtr head, temp;
    head = S->top;
    while (head)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    S->count=0;
    return OK;
}

/* 若栈S为空栈，则返回TRUE，否则返回FALSE */
Status StackEmpty(LinkStack S)
{
    if (!S.count)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }

}

/* 返回S的元素个数，即栈的长度 */
int StackLength(LinkStack S)
{
        return S.count;
}

/* 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR */
Status GetTop(LinkStack S,SElemType *e)
{
    if (S.count)
    {
        *e = S.top->data;
    }
    return OK;
}

/* 插入元素e为新的栈顶元素 */
Status Push(LinkStack *S,SElemType e)
{
    LinkStackPtr newNode =(LinkStackPtr)malloc(sizeof(StackNode));
    newNode->data = e;
    newNode->next = S->top;
    S->top = newNode;
    S->count ++; 
    return OK;
}

/* 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR */
Status Pop(LinkStack *S,SElemType *e)
{
    if (StackEmpty(*S))
    {
        return ERROR;
    }
    LinkStackPtr topNode = S->top;
    *e = S->top->data;
    S->top = topNode->next;
    free(topNode);
    S->count --;
    return OK;  
}

Status StackTraverse(LinkStack S)
{
    LinkStackPtr topNode = S.top;
    while(topNode)
    {
        visit(topNode->data);
        topNode = topNode->next;
    }
    return OK;
}

int main()
{
        int j;
        LinkStack s;
        int e;
        if(InitStack(&s)==OK)
                for(j=1;j<=10;j++)
                        Push(&s,j);
        printf("栈中元素依次为：");
        StackTraverse(s);
        Pop(&s,&e);
        printf("\n弹出的栈顶元素 e=%d\n",e);
        printf("栈空否：%d(1:空 0:否)\n",StackEmpty(s));
        GetTop(s,&e);
        printf("栈顶元素 e=%d 栈的长度为%d\n",e,StackLength(s));
        ClearStack(&s);
        printf("清空栈后，栈空否：%d(1:空 0:否)\n",StackEmpty(s));
        return 0;
}
