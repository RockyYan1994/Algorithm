/*
	实现O(1)space的方法是通过反转后面的list，然后比较。
*/

//version 1(O(n) space)
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
        vector<int> s;
        while (head) {
            s.push_back(head -> val);
            head = head -> next;
        }
        for (int i=0;i<s.size()/2;i++) {
            if (s[i] != s[s.size()-i-1]) return false;
        }
        return true;
    }
};