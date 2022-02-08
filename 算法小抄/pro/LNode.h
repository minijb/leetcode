#ifndef _LNODE_H_
#define _LNODE_H_

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

#endif