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
    int maxPathSum(TreeNode* root) {
        if (!root) {
            return MIN_INT;
        }
        int ans = root->val;
        maxSinglePathSum(root, ans);
        return ans;
    }
    
private:
    const int MAX_INT = ~0u >> 1;
    const int MIN_INT = -MAX_INT - 1;
    int maxSinglePathSum(TreeNode *root, int &ans) {
        if (!root) {
            return MIN_INT;
        }  
        int leftSum = maxSinglePathSum(root->left, ans), rightSum = maxSinglePathSum(root->right, ans);
        int maxPathSum = root->val;
        if (leftSum > 0) {
            maxPathSum = root->val + leftSum;
        }
        if (rightSum > 0) {
            maxPathSum = max(maxPathSum, root->val + rightSum);
        }
        ans = max(ans, root->val + ((leftSum > 0 ? leftSum : 0) + (rightSum > 0 ? rightSum : 0)));
        return maxPathSum;
    }
};