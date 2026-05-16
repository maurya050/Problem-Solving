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
    ListNode* getMiddle(ListNode *head){
        ListNode *slow = head;
        ListNode *fast = head->next;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode *merge(ListNode *left, ListNode *right){
        ListNode *dummy = new ListNode(0);
        ListNode *ans = dummy;

        while(left && right){
            if(left->val < right->val){
                dummy->next = left;
                left = left->next;
            }
            else{
                dummy->next = right;
                right = right->next;

            }
            dummy = dummy->next;
        }
        if(left)
            dummy->next = left;
        else
            dummy ->next = right;
        
        return ans->next;
    }

    ListNode* sortList(ListNode* head) {
        
        if(!head || !head->next)
            return head;
        ListNode *mid = getMiddle(head);

        ListNode *right = mid->next;
        mid->next = NULL;
        ListNode *left = sortList(head);
        right = sortList(right);
        return merge(left, right);
    }
};