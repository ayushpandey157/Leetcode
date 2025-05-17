class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        while (l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }

        ListNode* ans = nullptr;
        int carry = 0;
        while (!s1.empty() || !s2.empty() || carry) {
            int v1 = 0, v2 = 0;
            if (!s1.empty()) {
                v1 = s1.top(); 
                s1.pop();
            }
            if (!s2.empty()) {
                v2 = s2.top(); 
                s2.pop();
            }
            int sum = v1 + v2 + carry;
            carry = sum / 10;
            ListNode* node = new ListNode(sum % 10);
            node->next = ans;
            ans = node;
        }
        return ans;
    }
};