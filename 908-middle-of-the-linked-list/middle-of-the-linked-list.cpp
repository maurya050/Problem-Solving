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
    ListNode* middleNode(ListNode* head) {
        
        if(head == nullptr || head->next == nullptr)
            return head;
        int n = 0;
        ListNode* temp = head;
        while(temp){
            n++;
            temp = temp->next;
        }
        temp = head;
        int track=0;
        while(temp){
            track++;
            if(track == (n/2)+1){
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }
};