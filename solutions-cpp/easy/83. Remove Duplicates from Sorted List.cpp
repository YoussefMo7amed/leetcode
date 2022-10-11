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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *root = head;
        ListNode *next = NULL;
        if (head) next = head->next;
        while (next) {
            next = head->next;
            while (next && head->val == next->val) {
                next = next->next;
            }
            head->next = next;
            head = next;
        }
        return root;
    }
};