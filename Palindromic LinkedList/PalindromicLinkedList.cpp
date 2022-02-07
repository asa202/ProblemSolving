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
    ListNode* reverseList(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* findMiddleNode(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast){
            fast = fast->next;
            if(!fast) return slow;
            else{
                slow = slow->next;
                fast = fast->next;
            }
        }
        return slow;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* middleNode = findMiddleNode(head);
        ListNode* reversedHalf = reverseList(middleNode);
        ListNode* temp = head;
        while(reversedHalf && reversedHalf!=middleNode){
            if(temp->val!=reversedHalf->val) return false;
            temp = temp->next;
            reversedHalf = reversedHalf->next;
        }
        if(temp == reversedHalf) return true;
        
        if(temp && reversedHalf){
            if(temp->val == reversedHalf->val) return true;
        }
        return false;
    }
};