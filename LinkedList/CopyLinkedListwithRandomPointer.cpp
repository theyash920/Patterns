class Solution {
public:
    Node* copyRandomList(Node* head) {

        if (head == NULL) return NULL;

        Node *current = head;

        // Step 1: create interleaved list -> original, copy, original, copy...
        while (current != NULL) {
            Node* copy = new Node(current->val);
            copy->next = current->next;
            current->next = copy;
            current = copy->next;
        }

        // Step 2: assign random pointers to the copy nodes
        current = head;
        while (current != NULL) {
            if (current->random != NULL) {
                current->next->random = current->random->next;
            }
            current = current->next->next;
        }

        // Step 3: extract the copy list and restore the original list
        current = head;
        Node* dummy = new Node(0);
        Node *copy, *copyTail = dummy;
        Node* next = NULL;

        while (current != NULL) {
            next = current->next->next;

            // extract the copy
            copy = current->next;
            copyTail->next = copy;
            copyTail = copy;

            // restore the original list
            current->next = next;

            current = next;
        }

        return dummy->next;
    }
};
