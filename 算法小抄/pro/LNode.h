#ifndef _LNODE_H_
#define _LNODE_H_

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

#endif