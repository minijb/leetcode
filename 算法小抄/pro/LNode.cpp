#include <stdio.h>
#include <stdlib.h>
#define ElementType int

typedef struct LNode
{
    ElementType data;
    struct LNode *next;
}LNode, *LinkList;


//��ʼ���б�
void InitList(LinkList &L);
//��ʼ����������
void Init_insertList_head(LinkList &L);
//��ʼ��ʹ��β�巨�����б�
void Init_insertList_tail(LinkList &L);
//�õ��б�ĳ���
int Length(LinkList L);
//ͷ�巨
bool List_headInsert(LinkList &L,ElementType x);
//���뵽ָ��λ��
bool ListInsert(LinkList &L , int i , ElementType x);
//��ӡ����
void PrintList(LinkList L);
//��λ���
LNode * GetElem(LinkList L , int i);
//��ֵ���
int LocateElem(LinkList L , ElementType i);
//ɾ��ĳ���ڵ�
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
    int x;//����Ҫ����ĸ���
    LNode *p;//�ڵ�
    scanf("%d",&x);
    for(int i = 0 ; i <x ; i++){
        int n;
        scanf("%d",&n);
        List_headInsert(L,n);
    }
}

void Init_insertList_tail(LinkList &L){
    int x;//�������ĸ���
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