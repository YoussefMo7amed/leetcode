// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next)
            return head;
        int n = 0;
        ListNode* tmp = head;
        while(tmp->next){
            n++;
            tmp = tmp->next;
        }
        tmp->next = head;
        n++;
        k = k%n;
        k = n - k;
        tmp = head;
        while(k-- > 1){
            tmp = tmp->next;
        }
        head = tmp->next;
        tmp->next = NULL;
        return head;
    }
};
