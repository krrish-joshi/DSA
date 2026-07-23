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
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        // Step 1: find middle using slow/fast pointers
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: reverse second half (starting after slow)
        ListNode* secondHalf = reverse(slow->next);
        ListNode* firstHalf = head;

        // Step 3: compare both halves
        ListNode* secondHalfCopy = secondHalf; // keep for restoring later
        bool result = true;
        while (secondHalf) {
            if (firstHalf->val != secondHalf->val) {
                result = false;
                break;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        // Step 4 (optional): restore original list
        slow->next = reverse(secondHalfCopy);

        return result;
    }

private:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        while (head) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};