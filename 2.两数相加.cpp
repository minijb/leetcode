/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int tag = 0;//标志位用来检测是否需要进位
    //输入l1 , l2 返回一个相加节点并改变tag
    ListNode * add(ListNode *l1 , ListNode *l2,int &tag){
        ListNode *N = new ListNode(-1 ,NULL);
        int sum  = l1->val +l2->val;
        if(tag == 1) sum++;
        if(sum > 9){
            tag =1 ;
            N->val = sum  - 10;
        }else{
            tag = 0 ;
            N->val = sum;
        }
        return N;
    }


    //循环完毕如果tag还是1则在结尾添加一个节点
    void tail(ListNode *L , int &tag){
        ListNode *N = new ListNode(1 ,NULL);
        L->next = N;
    }

    void single(ListNode *L , int &tag){
        if(tag==1) (L->val)++;
        if(L->val>9){
            L->val -= 10;
            tag =1;
        }else{
            tag = 0;
        }
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *temp = add(l1,l2,tag);
        ListNode *L = temp; //同来移动的端点
        ListNode *L1 = L;
        l1= l1->next;
        l2 = l2->next;
        while(l1!=NULL&&l2!=NULL){
            ListNode *N = add(l1,l2,tag);
            l1= l1->next;
            l2 = l2->next;
            L->next = N;
            L = N;
        }
        if(l1!=NULL) L->next = l1;
        if(l2!=NULL) L->next = l2;
        if(l1==NULL && l2 == NULL){
            if(tag == 1){
                tail(L,tag);
            }
        }else{
            L=L->next;//进入余下数组
            while(L!=NULL&&tag==1){
                single(L,tag);
                L1= L;
                L=L->next;
            }
            if(L==NULL && tag ==1){
                tail(L1,tag);
            }
        }

     
        
        return temp;
    }
};