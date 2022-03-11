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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        
        int len = 1;
        ListNode *newHead, *tail;
        newHead = head;
        tail = head;
        
        while(tail->next){
            tail = tail->next;
            ++len;
        }
        
        k %= len;
        
        tail->next = head;
        
        for(int i = 0; i < len - k; ++i) tail = tail->next;
        
        newHead = tail->next; 
        tail->next = NULL;
        return newHead;
    }
};