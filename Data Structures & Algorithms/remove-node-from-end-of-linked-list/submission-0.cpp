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
        // removal is just changing what the pointers point too
        // I want to unlink the node before the ith node from the ith node and point it to the node after the ith node
        // temp = ith->next
        // ith->next = nullptr;
        // prev->next = temp
        // return prev

        // creates a fake prev node that points to the head node in case head is the node to remove
        ListNode* dummy = new ListNode(0, head);
        ListNode* left = dummy; // 0
        ListNode* right = head; // the original head

        // move right n steps ahead (now n steps ahead of left)
        while(n > 0)
        {
            right = right->next;
            n--;
        }

        // move both pointers forward until right reaches the end
        // left will be at the node right before the one to be removed
        while(right)
        {
            left = left->next;
            right = right->next;
        }

        // remove the target node
        left->next = left->next->next;
        //return the head
        return dummy->next;
    }
};
