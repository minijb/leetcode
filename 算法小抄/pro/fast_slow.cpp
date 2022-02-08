#include <iostream>
#include "LNode.h"
using namespace std;

/**
 * @brief
 * typedef struct LNode
    {
        ElementType data;
        struct LNode *next;
    }LNode, *LinkList;
 */

/**
 * @brief
 * 1.使用快慢指针来实现链表是否出现环
 * 2.使用快慢指针找到环的起点
 * 3.使用快慢指针找到链表的中点
 */

void create_cycle(LinkList head);

bool hasCycle(LinkList head);

int main()
{
    LinkList head;
    InitList(head);
    create_cycle(head);
    bool b = hasCycle(head);
    cout << b << endl;
    return 0;
}

bool hasCycle(LinkList head)
{
    LNode *fast, *slow;
    fast = slow = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if(fast==slow) return true;
    }
    return false;
}

void create_cycle(LinkList head)
{
    
    LinkList L1 = new LNode;
    LinkList L2 = new LNode;
    L2->data = 5;
    LinkList L3 = new LNode;
    LinkList L4 = new LNode;
    LinkList L5 = new LNode;
    LinkList L6 = new LNode;
    LinkList L7 = new LNode;
    L1->next = L2;
    L2->next = L3;
    L3->next = L4;
    L4->next = L5;
    L5->next = L6;
    L6->next = L7;
    L7->next = L3;
    head->next = L1;
}