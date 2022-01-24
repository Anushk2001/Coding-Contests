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
    // Great for Interview perspective
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* n1 = NULL;
        ListNode* n2 = NULL;
        for(auto curr = head;curr!=NULL;curr = curr->next)
        {
            (n2!=NULL)?n2 = n2->next:n2 = NULL;
            if(k!=0)
            {
                k--;
                if(k==0){
                    n1 = curr;
                    n2 = head;
                }
            }
        }
        swap(n1->val,n2->val);
        return head;
    }
};