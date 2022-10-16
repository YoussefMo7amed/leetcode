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
    ListNode *deleteMiddle(ListNode *head) {
        ListNode *slow = NULL, *fast = NULL;
        slow = head;
        fast = head->next;
        if (!fast) return NULL;

        while (fast && fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *deletedNode = slow->next;
        slow->next = slow->next->next;
        delete deletedNode;
        return head;
    }
};