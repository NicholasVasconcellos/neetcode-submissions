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

        // Starting at the head of each list
        // Add the number, if there is a carry (>10)
        // Store the carry and add on the next one
        // Repeat until both Lists pointer are null
        // Return the new List Header


        ListNode* l3_head = new ListNode();

        // Add in Line while creating new Linked List
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* p3 = l3_head;

        int carry = 0;

        while(p1 || p2 || carry > 0){
            // add the numbers
            int sum = 0;
            if(p1){sum += p1->val;}
            if(p2){sum += p2->val;}
            sum += carry;

            // Get the lowest digit 0 - 9
            int digit = sum % 10;

            // Update Carry: it's the largest significance digit
            carry = sum / 10;

            

            // Create Next Node on List 3
            p3->next = new ListNode(digit); 

            // Update pointers
            if(p1){p1 = p1->next;}
            if(p2){p2 = p2->next;}
            p3 = p3->next;
            
        }

        return l3_head->next;
        
    }
};
