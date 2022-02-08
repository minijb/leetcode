#include <stdio.h>
#include <stdlib.h>
#define ElementType int

typedef struct LNode
{
    ElementType data;
    struct LNode *next;
}LNode, *LinkList;


//初始化列表
void InitList(LinkList &L);
//初始化增加链表
void Init_insertList_head(LinkList &L);
//初始化使用尾插法建立列表
void Init_insertList_tail(LinkList &L);
//得到列表的长度
int Length(LinkList L);
//头插法
bool List_headInsert(LinkList &L,ElementType x);
//插入到指定位置
bool ListInsert(LinkList &L , int i , ElementType x);
//打印链表
void PrintList(LinkList L);
//按位查表
LNode * GetElem(LinkList L , int i);
//按值查表
int LocateElem(LinkList L , ElementType i);
//删除某个节点
bool DeleteElem(LinkList L , int i,ElementType &x);


// int main(){
//     LinkList L;
//     InitList(L);
//     Init_insertList_tail(L);
//     printf("\n%d\n",ListInsert(L,4,100));
//     // int n;
//     // DeleteElem(L,4,n);
//     PrintList(L);
//     // printf("\n");
//     // LNode *Q=GetElem(L,3);
//     // int n = LocateElem(L,3);
//     // printf("%d",n);

//     return 0;
// }

void InitList(LinkList &L){
    L = (LNode *)malloc(sizeof(LNode));
    L->next = NULL;
}

int Length(LinkList L){
    int i = 0;
    LNode * p =L;
    while(p->next != NULL){
        i++;
        p=p->next;
    }
    return i;
}

bool List_headInsert(LinkList &L,ElementType x){
    if(L==NULL) return false;
    LNode *s =(LNode *)malloc(sizeof(LNode));
    LNode *follow = L->next;
    s->data =x ;
    L->next = s;
    s->next = follow;
    return true;
}
bool ListInsert(LinkList &L , int i , ElementType x){
    LNode * P = L;
    for(int n =0 ; n < i-1 ; n++){
        if(P==NULL) return false;
        P = P->next;
    }
    LNode *N = (LNode*)malloc(sizeof(LNode));
    N->data = x;
    N->next = P->next;
    P->next = N;
    return true;
}

void Init_insertList_head(LinkList &L){
    int x;//输入要插入的个数
    LNode *p;//节点
    scanf("%d",&x);
    for(int i = 0 ; i <x ; i++){
        int n;
        scanf("%d",&n);
        List_headInsert(L,n);
    }
}

void Init_insertList_tail(LinkList &L){
    int x;//输入插入的个数
    LNode *p;
    LinkList S = L;
    scanf("%d",&x);
    for(int i = 0 ; i<x;i++){
        p=(LNode*)malloc(sizeof(LNode));
        int n;
        scanf("%d",&n);
        p->data = n;
        p->next = NULL;
        S->next =p;
        S= p ;
    }
}

void PrintList(LinkList L){
    LNode *p =L->next;
    while(p!=NULL){
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

LNode * GetElem(LinkList L , ElementType i){
    LinkList Q = L;
    if(L==NULL||i<0) return NULL;
    for(int n = 0 ; n<i ; n++){
        Q = Q->next;
    }
    return Q;
}

int LocateElem(LinkList L , ElementType i){
    LinkList Q = L;
    int n=0;
    do{
        Q=Q->next;
        n++;
    }while(Q->data!=i&&Q!=NULL);
    return n;
}

bool DeleteElem(LinkList L , int i , ElementType &x){
    LinkList Q =GetElem(L,i-1);
    if(Q==NULL) return false;
    LNode * d = Q->next;
    Q->next = d->next;
    free(d);
    return true;    

}