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
    void reorderList(ListNode* head) {
        ListNode* slow = head;

        // Starting fast at head->next ensures that for even-length lists
        //slow stops at the correct midpoint instead of overshooting.
        ListNode* fast = head->next;

        //find the middle of the list. When fast reaches the end of the list
        // slow will be the midpoint
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // now we want to reverse the second half of the list based on slow(the midpoint)
        ListNode* secondHalf = slow->next;
        // this officially separates the two lists by setting the end of the second list to point to null
        ListNode* prev = slow->next = nullptr; 
        while(secondHalf)
        {
            ListNode* temp = secondHalf->next;
            secondHalf->next = prev;
            prev = secondHalf;
            secondHalf = temp;
        }

        // now we want to merge the two halves in alternating order
        ListNode* firstHalf = head;
        secondHalf = prev; // prev is the head of the secondHalf based on the reverse we did above
        while(secondHalf)
        {
            ListNode* temp1 = firstHalf->next;
            ListNode* temp2 = secondHalf->next;
            firstHalf->next = secondHalf;
            secondHalf->next = temp1;
            firstHalf = temp1;
            secondHalf = temp2;
        }

        
    }
};
