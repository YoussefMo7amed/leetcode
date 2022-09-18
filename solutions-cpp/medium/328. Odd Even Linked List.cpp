 
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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return head;
        ListNode* odd_head = head;
        ListNode* even_head = head->next;

        ListNode* todd = odd_head;
        ListNode* teven = even_head;

        while (todd !=NULL && todd->next != NULL) {
            // todd = 1..2..3..4..5

            // teven = (2)..3..4..5
            teven = todd->next;

            // todd = 1..(3)..4..5
            todd->next = teven->next;

            // teven = 2..(4)..
            if(todd->next)
                teven->next = todd->next->next;


            teven = teven->next;
            if (todd->next) todd = todd->next;
        }
        todd->next = even_head;
        return odd_head;
    }
};
