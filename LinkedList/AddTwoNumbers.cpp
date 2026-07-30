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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* sumHead = nullptr;
        ListNode* sumTail = nullptr;

        //p1 & p2
        ListNode* p1 = l1;
        ListNode* p2 = l2;

        //start with 0
        int carry = 0;
         while(p1 && p2){
            int digit = p1 -> val + p2 -> val;
            digit += carry;

            if(digit > 9){
                digit = digit % 10;
                carry = 1;
            }else{
                carry = 0;
            }
            if(sumHead == nullptr){
                sumHead = new ListNode(digit);
                sumTail = sumHead;
            }
            else{
                ListNode* newNode = new ListNode(digit);
                sumTail -> next = newNode;
                sumTail = newNode;
            }

            p1 = p1 -> next;
            p2 = p2 -> next;
         }
         while(p1){
            int digit = p1 -> val;
            digit += carry;

            if(digit > 9){
                digit = digit % 10;
                carry = 1;
            }else{
                carry = 0;
            }
            if(sumHead == nullptr){
                sumHead = new ListNode(digit);
                sumTail = sumHead;
            }
            else{
                ListNode* newNode = new ListNode(digit);
                sumTail -> next = newNode;
                sumTail = newNode;
            }

            p1 = p1 -> next;
         }
         while(p2){
            int digit = p2 -> val;
            digit += carry;

            if(digit > 9){
                digit = digit % 10;
                carry = 1;
            }else{
                carry = 0;
            }
            if(sumHead == nullptr){
                sumHead = new ListNode(digit);
                sumTail = sumHead;
            }
            else{
                ListNode* newNode = new ListNode(digit);
                sumTail -> next = newNode;
                sumTail = newNode;
            }

            p2 = p2 -> next;
         }

         if(carry == 1){
            if(sumHead == nullptr){
                sumHead = new ListNode(1);
                sumTail = sumHead;
            }else{
                ListNode* newNode = new ListNode(1);
                sumTail -> next = newNode;
                sumTail = newNode;
            }

         }
         
         return sumHead;

        
    }
};
