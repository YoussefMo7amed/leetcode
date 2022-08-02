class Solution {
   public:
    ListNode *swapPairs(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        // 1->2->3->4

        // next = 2
        ListNode *next = head->next;

        // 1 -> recursion()
        head->next = swapPairs(head->next->next);
        // 2 -> 1 -> what came from recursion (swapping the other pairs)
        next->next = head;
        // 2->1->4->3
        return next;
    }
};
