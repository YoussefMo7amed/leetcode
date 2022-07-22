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
    ListNode* sortList(ListNode* head) {
        // using merge sort algorithm
        if (!head || !head->next) {
            return head;
        }
        // split the list into two halfs
        ListNode* left = head;
        ListNode* right = mid(head);
        ListNode* temp = right->next;
        right->next = NULL;
        right = temp;
        left = sortList(left);
        right = sortList(right);
        return merge(left, right);
    }
    ListNode* mid(ListNode* head) {
        ListNode *slow = head, *fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode dummy(0);
        ListNode *tail = &dummy ;
        while (left && right) {
            if (left->val < right->val) {
                tail->next = left;
                left = left->next;
            } else {
                tail->next = right;
                right = right->next;
            }
            tail = tail->next;
        }
        if (left) tail->next = left;
        if (right) tail->next = right;
        return dummy.next;
    }
};
=====================
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
    ListNode* sortList(ListNode* head) {
        vector<int> v;
        ListNode* tmp = head;
        while(tmp){
            v.push_back(tmp->val);
            tmp = tmp->next;
        }
        sort(v.begin(), v.end());
        tmp = head;
        for(int i: v){
            tmp->val = i;
            tmp = tmp->next;
        }
        return head;
    }
};
