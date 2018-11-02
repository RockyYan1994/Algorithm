/*
	方法一：采用栈存储上一个父节点，
	方法二：在preorder上进行存储，通过i指向当前最新的节点，感觉不是很实用，会改变原有的数组。
*/

//version 1(28 ms)
class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        if (preorder.empty()) return true;
        int last = INT_MIN;
        stack<int> s;
        for (int i=0; i<preorder.size(); i++) {            
            while (!s.empty() && s.top() < preorder[i]) {
                last = s.top();
                s.pop();
            }
            if (preorder[i] < last) return false;
            s.push(preorder[i]);                        
        }
        return true;
    }
};

//version 2(24 ms)
class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        if (preorder.empty()) return true;
        int low = INT_MIN, i = -1;
        for (auto num : preorder) {
            if (num < low) {
                return false;
            }
            while (i>=0 && num > preorder[i]) {
                low = preorder[i--];
            }
            preorder[++i] = num; 
        }
        return true;
    }
};