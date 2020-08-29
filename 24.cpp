/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *priv=new ListNode;
        priv->next=head;
        ListNode *res=priv;
        ListNode *h,*h_n;
        while(priv->next&&priv->next->next){
            h=priv->next;
            h_n=priv->next->next->next;
            priv->next=priv->next->next;
            priv->next->next=h;
            h->next=h_n;
            priv=priv->next->next;    
        }
        return res->next;
    }
};