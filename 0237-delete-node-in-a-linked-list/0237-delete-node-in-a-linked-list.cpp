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
    void deleteNode(ListNode* node) {
        ListNode* curr = node;
        ListNode* temp;
        while (curr->next) {
            curr->val = curr->next->val;
            temp = curr;
            curr = curr->next;
        }
        temp->next = nullptr;
    }
};