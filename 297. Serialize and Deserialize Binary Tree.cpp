/*
	方法一：采用直接encode成[a,b,c]的形式，然后强行decode。然而特别慢。。
	方法二：通过string 的" "来做结尾符号，通过istringstream和ostringstream来辅助，通过递归实现。
*/

//version 1(100 ms)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "[]";
        string res = "[";
        queue<TreeNode*> q;
        q.push(root);
        res += to_string(root->val) + ",";
        while (!q.empty()) {
            int len = q.size();
            for (int i=0; i<len; i++) {
                TreeNode* cur = q.front();
                q.pop();
                if (cur->left) {
                    res += to_string(cur->left->val) + ",";
                    q.push(cur->left);
                } else {
                    res += "null,";
                }
                if (cur->right) {
                    res += to_string(cur->right->val) + ",";
                    q.push(cur->right);
                } else {
                    res += "null,";
                }                
            }
        }
        if (res[res.size()-1] == ',') res[res.size()-1] = ']';
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "[]") return NULL;
        queue<TreeNode*> q;
        int i=1, k=1;
        while (data[k] != ',' && data[k] != ']') k++;
        string root_str = data.substr(i, k-i);
        TreeNode* root = new TreeNode(stoi(root_str));  
        i = k+1;
        q.push(root);
        while (!q.empty() && i < data.size()-1) {
            int size = q.size();
            for (int j=0; j<size; j++) {
                TreeNode* cur = q.front();
                q.pop();
                i = helper(q, cur, data, i, true);
                i = helper(q, cur, data, i, false);
            }
        }
        return root;
    }
    
    int helper(queue<TreeNode*>& q, TreeNode* root, string data, int i, bool l) {
        int k = i;
        while (data[k] != ',' && data[k] != ']') k++;
        string cur = data.substr(i, k-i);
        if (cur != "null") {            
            TreeNode* node = new TreeNode(stoi(cur));            
            q.push(node);   
            if (l) root->left = node;
            else root->right = node;
        }
        return k+1;
    }
};

//version 2(20 ms)
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream oss;
        serializeHelper(oss, root);
        return oss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream iss(data);
        TreeNode* root = deserializeHelper(iss);
        return root;
    }
private:
    void serializeHelper(ostringstream& oss, TreeNode* root) {
        if (!root) {
            oss << "# ";
            return;
        }
        oss << to_string(root->val) << " ";
        serializeHelper(oss, root->left);
        serializeHelper(oss, root->right);
    }
    
    TreeNode* deserializeHelper(istringstream& iss) {
        string cur;
        iss >> cur;
        if (cur == "#") return nullptr;
        TreeNode* root = new TreeNode(stoi(cur));
        root->left = deserializeHelper(iss);
        root->right = deserializeHelper(iss);
        return root;
    }
};