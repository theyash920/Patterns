class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* low = head;
        ListNode* high = head;

        while (high != NULL && high->next != NULL) {
            low = low->next;
            high = high->next->next;
            if (low == high) {
                return true;
            }
        }
        return false;
    }
};