#include "stdio.h"
#include "string.h"
#include "ctype.h"
#include "stdlib.h"

#include "math.h"
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;   /* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int ElemType; /* ElemType类型根据实际情况而定，这里假设为int */


Status visit(ElemType c)
{
    printf("%d ",c);
    return OK;
}

/*
 * 链表节点结构体
 * 数据域
 * 指针域
 */
typedef struct Node
{
    ElemType data;
    struct Node *next;
}Node;

// 链表声明
typedef struct Node *LinkList;

/*
 * 初始化链表
 */
Status InitList(LinkList *L)
{
    *L=(LinkList)malloc(sizeof(Node)); /* 产生头结点,并使L指向此头结点 */
    if(!(*L)) /* 存储分配失败 */
            return ERROR;
    (*L)->next=NULL; /* 指针域为空 */

    return OK;
}

/*
 * 判断链表是否为空
 * 初始条件：表L已存在。
 * 操作结果：若L为空表，则返回TRUE，否则返回FALSE
 */
Status ListEmpty(LinkList L)
{
    if (L->next)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

/* 初始条件：表L已存在。操作结果：将L重置为空表 */
Status ClearList(LinkList L)
{
    LinkList head, temp;
    head = L->next;
    while(head)
    {
        temp = head->next;
        free(head);
        head = temp;
    }
    L->next = NULL;

    return OK;
}

/*
 * 查询链表长度
 * 初始条件：表L已存在
 * 操作结果：返回L中数据元素个数
 */
int ListLength(LinkList L)
{
    LinkList head = L->next;
    int count = 0;
    while(head)
    {
        ++ count;
        head = head->next;
    }
    return count;
}

/*
 * 获取链表指定位置的元素
 * 初始条件：表L已存在，1≤i≤ListLength(L)
 * 操作结果：用e返回L中第i个数据元素的值
 */
Status GetElem(LinkList L,int i,ElemType *e)
{
    int index = 0;
    LinkList head = L->next;
    while(head)
    {
        ++ index;
        if (index == i)
        {
            *e = head->data;
            return OK;
        }
        else if (index >i )
        {
            return ERROR;
        }
        head = head->next;
    }
    if ( !head || index > i)
    {
        return ERROR;
    }

    return OK;

}

/*
 * 在查找链表中指定的元素
 * 初始条件：顺序表L已存在
 * 操作结果：返回L中第1个与e满足关系的数据元素的位序。
 * 若这样的数据元素不存在，则返回值为0
 */
int LocateElem(LinkList L,ElemType e)
{
    LinkList head = L->next;
    int index = 0;
    while(head)
    {
        ++ index;
        if (head->data == e)
        {
            return index;
        }
        head = head->next;
    }

    return index;
}


/*
 * 在链表的指定位置插入元素
 * 初始条件：表L已存在,1≤i≤ListLength(L),
 * 操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1
 */
Status ListInsert(LinkList *L,int i,ElemType e)
{
    LinkList head, neck;
    head = *L;
    int index = 0;
    while(head)
    {
        ++ index;
        if (index == i)
        {
            LinkList newNode = (LinkList) malloc (sizeof(Node));
            newNode->data = e;
            newNode->next = head->next;
            head->next = newNode;
            return OK;
        }
        else if (index >= i)
        {
            return ERROR;
        }
        head = head->next;
    }

    return OK;
}

/*
 * 删除链表指定位置的数据元素
 * 初始条件：表L已存在，1≤i≤ListLength(L)
 * 操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1
 */
Status ListDelete(LinkList L,int i,ElemType *e)
{
    LinkList head, neck;
    head = L->next;
    int index = 0;
    while(head)
    {
        ++ index;
        if (index == i)
        {
            neck = head;
            head = neck->next;
            return OK;
        }
        else if (index > i)
        {
            return ERROR;
        }
        head = head->next;
    }
    return OK;
}

/*
 * 遍历输出链表元素
 * 初始条件：表L已存在
 * 操作结果：依次对L的每个数据元素输出
 */
Status ListTraverse(LinkList L)
{
    LinkList head = L->next;
    while(head)
    {
        visit(head->data);
        head = head->next;
    }
    return OK;
}

/*  随机产生n个元素的值，建立带表头结点的单链线性表L（头插法） */
void CreateListHead(LinkList *L, int n)
{
    srand(time(0));
    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next = NULL;

    for (int i=0; i<n; i++)
    {
        LinkList head = (LinkList)malloc(sizeof(Node));
        head->data = rand()%100+1;
        head->next = (*L)->next;
        (*L)->next = head;
    }
}

/*  随机产生n个元素的值，建立带表头结点的单链线性表L（尾插法） */
void CreateListTail(LinkList L, int n)
{
    LinkList tail;
    srand(time(0));
    L = (LinkList)malloc(sizeof(Node));
    tail = L;
    for (int i=0; i<n; i++)
    {
        LinkList newNode = (LinkList)malloc(sizeof(Node));
        newNode->data = rand()%100+1;
        tail->next = newNode;
        tail = newNode;
    }
    tail->next = NULL;
}

int main()
{
    printf("链表测试\n");
    LinkList L;
    ElemType e;
    Status i;
    int j,k;
    i=InitList(&L);
    printf("初始化L后：ListLength(L)=%d\n",ListLength(L));
    for(j=1;j<=5;j++)
            i=ListInsert(&L,1,j);
    printf("在L的表头依次插入1～5后：L.data=");
    ListTraverse(L);

    printf("ListLength(L)=%d \n",ListLength(L));
    i=ListEmpty(L);
    printf("L是否空：i=%d\t(1:是 0:否)\n",i);

    i=ClearList(L);
    printf("清空L后：ListLength(L)=%d\n",ListLength(L));
    i=ListEmpty(L);
    printf("L是否空：i=%d\t(1:是 0:否)\n",i);

    for(j=1;j<=10;j++)
            ListInsert(&L,j,j);
    printf("在L的表尾依次插入1～10后：L.data=");
    ListTraverse(L);

    printf("ListLength(L)=%d \n",ListLength(L));

    ListInsert(&L,1,0);
    printf("在L的表头插入0后：L.data=");
    ListTraverse(L);
    printf("ListLength(L)=%d \n",ListLength(L));

    GetElem(L,5,&e);
    printf("第5个元素的值为:%d\n",e);
    for(j=3;j<=4;j++)
    {
            k=LocateElem(L,j);
            if(k)
                    printf("第%d个元素的值为:%d\n",k,j);
            else
                    printf("没有值为%d的元素:\n",j);
    }


    k=ListLength(L); /* k为表长 */
    for(j=k+1;j>=k;j--)
    {
            i=ListDelete(L,j,&e); /* 删除第j个数据 */
            if(i==ERROR)
                    printf("删除第%d个数据失败\n",j);
            else
                    printf("删除第%d个的元素值为：%d\n",j,e);
    }
    printf("依次输出L的元素：");
    ListTraverse(L);

    j=5;
    ListDelete(L,j,&e); /* 删除第5个数据 */
    printf("删除第%d个的元素值为：%d\n",j,e);

    printf("依次输出L的元素：");
    ListTraverse(L);

    i=ClearList(L);
    printf("\n清空L后：ListLength(L)=%d\n",ListLength(L));
    CreateListHead(&L,20);
    printf("整体创建L的元素(头插法)：");
    ListTraverse(L);

    i=ClearList(L);
    printf("\n删除L后：ListLength(L)=%d\n",ListLength(L));
    CreateListTail(L,20);
    printf("整体创建L的元素(尾插法)：");
    ListTraverse(L);

    return 0;
}
