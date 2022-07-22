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
    ListNode* partition(ListNode* head, int x) {
    ListNode* pointer = head;

    ListNode* left_head = NULL;
    ListNode* left_pointer = NULL;

    ListNode* right_head = NULL;
    ListNode* right_pointer = NULL;

    while (pointer != NULL) {
        if (pointer->val < x) {
            if (left_head == NULL) {
                left_head = pointer;
                left_pointer = left_head;
            } else {
                left_pointer->next = pointer;
                left_pointer = left_pointer->next;
            }
        } else {
            if (right_head == NULL) {
                right_head = pointer;
                right_pointer = right_head;
            } else {
                right_pointer->next = pointer;
                right_pointer = right_pointer->next;
            }
        }
        pointer = pointer->next;
    }

    if (right_pointer) right_pointer->next = NULL;
    if (left_pointer) left_pointer->next = NULL;

    if (left_head != NULL) {
        left_pointer->next = right_head;
        return left_head;
    } else {
        return right_head;
    }
    }
};
