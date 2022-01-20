
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        deque <int> a, b;
        while(l1!=NULL){
            a.push_front(l1->val);
            l1 = l1->next;
        }
        while(l2!=NULL){
            b.push_front(l2->val);
            l2 = l2->next;
        }
        ListNode *ans = new ListNode();
        ans->val = 0;
        ans->next = NULL;
        ListNode *help = ans;
        int sum;
        while(a.size() && b.size()){
            ListNode *newDigit = new ListNode();
            newDigit->next = NULL;
            help->next = newDigit;
            sum = a.back() + b.back ();
            // cout << a.back() << '\t' << b.back() << endl;
            if(sum < 10){
                newDigit->val = sum;
                a.pop_back();
                b.pop_back();
            } else {
                newDigit->val = sum%10;
                a.pop_back();
                b.pop_back();
                if(a.size() == b.size() && a.empty())
                    a.push_back(0);
                if(a.size() > b.size()){
                    int d = a.back() + 1;
                    a.pop_back();
                    a.push_back(d);
                } else {
                    int d = b.back() + 1;
                    b.pop_back();
                    b.push_back(d);
                }
            }
            help = help->next;
        }
        while (a.size()){
            ListNode *newDigit = new ListNode();
            newDigit->next = NULL;
            if(a.back() > 9){
                newDigit->val = a.back()%10;
                a.pop_back();
                if(a.size()){
                    int d = a.back();
                    a.pop_back();
                    a.push_back(d + 1);
                } else {
                    if(newDigit->val == 0)
                        a.push_back(1);
                }
            } else {
                newDigit->val = a.back();
                a.pop_back();
            }
            help->next = newDigit;
            help = help->next;
        }

        while (b.size()){
            ListNode *newDigit = new ListNode();
            newDigit->next = NULL;
            if(b.back() > 9){
                newDigit->val = b.back()%10;
                b.pop_back();
                if(b.size()){
                    int d = b.back();
                    b.pop_back();
                    b.push_back(d + 1);
                } else {
                    if(newDigit->val == 0)
                        b.push_back(1);
                }
            } else {
                newDigit->val = b.back();
                b.pop_back();
            }
            help->next = newDigit;
            help = help->next;
        }
        return ans->next;
    }
};
