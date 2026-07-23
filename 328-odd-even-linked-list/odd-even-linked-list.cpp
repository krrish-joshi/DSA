/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* odd = head;          // starts at node 1
        ListNode* even = head->next;   // starts at node 2
        ListNode* evenHead = even;     // remember where even chain starts

        while (even && even->next) {
            odd->next = even->next;    // link odd to next odd node
            odd = odd->next;

            even->next = odd->next;    // link even to next even node
            even = even->next;
        }

        odd->next = evenHead;  // attach even chain at the end of odd chain

        return head;
    }
};