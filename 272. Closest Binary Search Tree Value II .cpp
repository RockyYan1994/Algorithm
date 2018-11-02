/*
	方法一：通过遍历所有元素
	方法二：通过先中顺遍历，然后binary找到中间，最后从中间往两边找。
*/

//version 1(12 ms)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> vals;
        travels(root, vals);
        map<double, vector<int>> m;
        for (auto val : vals) {
            double diff = abs(val - target);
            m[diff].push_back(val);
        }
        vector<int> res;
        map<double, vector<int>>::iterator it = m.begin();
        for (int i=0; i<k;) {
            for (auto val : it->second) {
                res.push_back(val);
                i++;
            }
            it++;
        }
        return res;
    }
    void travels(TreeNode* root, vector<int>& vals) {
        if (!root) return;
        vals.push_back(root->val);
        travels(root->left, vals);
        travels(root->right, vals);
    }
};

//version 2(8 ms)/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> vals, res;
        inorder_travels(root, vals);
        int l = binarySearch(vals, target);
        int r = l+1;
        while (k-- > 0) {
            if (r >= vals.size()) res.push_back(vals[l--]);
            else if (l>=0 && abs((double)vals[l]-target) < abs((double)vals[r]-target)) {
                res.push_back(vals[l--]);                
            } else {
                res.push_back(vals[r++]);
            }
        }
        return res;
    }
    
    
    void inorder_travels(TreeNode* root, vector<int>& vals) {
        if (!root) return;
        inorder_travels(root->left, vals);
        vals.push_back(root->val);
        inorder_travels(root->right, vals);
    }
    
    int binarySearch(vector<int> vals, double target) {
        int l = 0, r = vals.size()-1;
        while (l < r) {
            int mid = l + (r-l)/2;
            if (vals[mid] < target) {
                l = mid + 1;                
            } else if (vals[mid] > target) {
                r = mid - 1;
            } else {
                return mid;
            }
        }
        if (l > 0) return abs((double)vals[l] - target) < abs((double)vals[l-1] - target) ? l : l - 1;
        return l;
    }
};