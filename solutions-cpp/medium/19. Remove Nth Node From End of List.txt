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
        ListNode *tmp =head;
        int ln = 0;
        while(tmp){
            ln++;
            tmp = tmp->next;
        }
        if(ln == 1)
            return NULL;
        if(ln == n)
            return head->next;
        tmp = head;
        int cnt = 0;
        while(tmp->next != NULL && ln - cnt != n + 1){
            cnt++;
            tmp = tmp->next;
        }

        ListNode* node_to_be_deleted = tmp->next;
        tmp->next = node_to_be_deleted->next;
        delete(node_to_be_deleted);

        return head;
    }
};
=============================
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
        ListNode* cur = head;
        int len = 0;
        while (cur != NULL) {
            len++;
            cur = cur->next;
        }
        cur = head;
        if(len == 1)
            return NULL;
        if(len == n)
            return head->next;
        while (cur != NULL && len != n) {
            if (len - 1 == n) {
                cur->next = cur->next->next;
                break;
            }
            len --;
            cur = cur->next;
        }
        return head;
    }
};
