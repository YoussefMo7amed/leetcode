/*
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
*/
class Solution {
   public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode *root = NULL;
        int idx = -1;
        for (int i = 0; i < lists.size(); i++) {
            if (!root || lists[i] && lists[i]->val < root->val) {
                root = lists[i];
                idx = i;
            }
        }
        
        if (!root) return NULL;
        
        lists[idx] = lists[idx]->next;
        ListNode *current = root, *next = NULL;
        
        while (current) {
            next = NULL;
            for (int i = 0; i < lists.size(); i++) {
                if (!next || (lists[i] && lists[i]->val < next->val)) {
                    next = lists[i];
                    idx = i;
                }
            }
            if (lists[idx]) lists[idx] = lists[idx]->next;
            current->next = next;
            current = next;
        }
        
        return root;
    }
};
