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
    ListNode *reverse(ListNode *head){
        ListNode *prev = NULL;
        ListNode *curr = head;

        while(curr != NULL){
            ListNode *nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *rev = reverse(slow);

        while(rev != NULL){
            if(rev->val != head->val)
                return false;
            rev = rev->next;
            head = head->next;
        }
        return true;
    }
};