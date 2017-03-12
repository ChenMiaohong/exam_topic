#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef int ElemType;
typedef int Status;
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef struct Node{
    ElemType data;
    struct Node *next;
}Node;
typedef struct Node *LinkList;
Status InitList(LinkList *L)
{
    *L=(LinkList)malloc(sizeof(Node));
    if(!(*L))
        return -1;
    (*L)->next=NULL;
    return 0;
}
/*Status InsertList(LinkList *L,int i,ElemType e)
{
    int j=1;
    LinkList p,s;
    p=*L;
    while(p&&j<i)
    {
        p=p->next;
        ++j;
    }
    if(!p||j>i)
        return 0;
    s=(LinkList)malloc(sizeof(Node));
    s->data=e;
    s->next=p->next;
    p->next=s;
    return 1;
}*/
Status ListInsert(LinkList *L,int i,ElemType e)
{
	int j;
	LinkList p,s;
	p = *L;
	j = 1;
	while (p && j < i)     /* 寻找第i个结点 */
	{
		p = p->next;
		++j;
	}
	if (!p || j > i)
		return ERROR;   /* 第i个元素不存在 */
	s = (LinkList)malloc(sizeof(Node));  /*  生成新结点(C语言标准函数) */
	s->data = e;
	s->next = p->next;      /* 将p的后继结点赋值给s的后继  */
	p->next = s;          /* 将s赋值给p的后继 */
	return OK;
}
void ListSort(LinkList L)
{
    LinkList p;
    LinkList q;
    p=L->next;
    int count=10;
    int j=1;
    while(count>1)
    {


        while(p->next!=NULL)
        {
            if(p->data>p->next->data)
            {
                 int temp;
                temp=p->data;
                p->data=q->next->data;
                q->next->data=temp;
            }
            p=p->next;
        }
        count--;
    p=L->next;
    }
}
void visit(ElemType c)
{
    printf("%d ",c);
}
Status ListTraverse(LinkList L)
{
    LinkList p=L->next;
    while(p)
    {
        visit(p->data);
        p=p->next;
    }
   printf("\n");
    return 0;
}
int main()
{
    LinkList L;
    int i;
    int num[10]={15,25,36,58,96,47,25,26,18,47};
    InitList(&L);
    for(i=0;i<10;i++)
    {
        ListInsert(&L,i+1,num[i]);
        //printf("%d ",num[i]);
        printf("\n");
    //ListTraverse(L);

    }

        ListSort(L);
        //ListTraverse(L);



}
