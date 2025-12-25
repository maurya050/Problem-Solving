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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode *temp = head;
        int count = 0;
        while(temp){
            temp = temp->next;
            count++;
        }
        int target = count - n;
        temp = head;
        count = 0;
        if(target == 0){
            return head->next;
        }
        ListNode *back;
        while(temp && count < target){
            back = temp;
            temp = temp->next;
            count++;
        }
        back->next = temp->next;
        return head;

    }
};