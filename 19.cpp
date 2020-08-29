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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> res;
        ListNode *tmp=head;
        while(tmp){
            res.push_back(tmp);
            tmp=tmp->next;
        }
        int tar=res.size()-n;
        if(tar==0){
            ListNode* t=head;
            head=head->next;
        }else{
            ListNode *t=res[tar];
            res[tar-1]->next=t->next;
            t->next=NULL;
        }
        return head;
    }
};