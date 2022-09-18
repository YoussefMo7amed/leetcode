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
#define SIZEOF(a) sizeof(a)/sizeof(*a)

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* cur;
        if(!list1)
            return list2;
        if(!list2)
            return list1;
        if (list1->val <= list2->val){
            cur = list1;
            list1 = list1->next;
        } else {
            cur = list2;
            list2 = list2->next;
        }
        ListNode* lst = cur;
        while(list1 || list2){
            if(!list1){
                cur->next = list2;
                break;
            }
            if(!list2){
                cur->next = list1;
                break;
            }
            if(list1 && list1->val <= list2->val){
                cur->next = list1;
                list1 = list1->next;
            } else {
                if(list2){
                    cur->next = list2;
                    list2 = list2->next;
                }
            }
            cur = cur->next;
        }

        return lst;
    }
};
