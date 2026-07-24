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
        ListNode *curr = head, *prev = NULL, *curr1=head;
        int len = 0;
        while(curr1 != NULL){
            len++;
            curr1 = curr1 -> next;
        }
        int n1 = len -n;
        int count = 0;

        if(n1 == 0){
            head =head -> next;
        }
        else{
            while(n1 >0){
               prev = curr;
               curr = curr -> next;
               n1--;
               if(n1 == 0){
                prev -> next = curr -> next;
               }
            }
        }
        return head;
    }
};
