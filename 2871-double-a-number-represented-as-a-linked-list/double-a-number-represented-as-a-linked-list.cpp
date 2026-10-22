class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* forward = curr->next;
            curr->next = pre;
            pre = curr;
            curr = forward;
        }
        return pre;
    }

    ListNode* doubleIt(ListNode* head) {
        // If the first digit is >= 5, doubling creates a new leading digit
        if (head->val >= 5) {
            head = new ListNode(0, head);
        }

        ListNode* curr = head;

        while (curr != nullptr) {
            curr->val = (curr->val * 2) % 10;

            if (curr->next != nullptr && curr->next->val >= 5) {
                curr->val += 1;
            }

            curr = curr->next;
        }

        return head;
    }
};