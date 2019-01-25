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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (!root) {
            return ans;
        }
        stack<pair<TreeNode *, int>> s;
        s.push({root, 0});
        while (!s.empty()) {
            auto &t = s.top();
            if (t.second == 0) {
                t.second = 1;
                if (t.first->left) {
                    s.push({t.first->left, 0});
                }
            } else if (t.second == 1) {
                t.second = 2;
                if (t.first->right) {
                    s.push({t.first->right, 0});
                }
            } else {
                ans.push_back(t.first->val);
                s.pop();
            }
        }
        return ans;
    }
};