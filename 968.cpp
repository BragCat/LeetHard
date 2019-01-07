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
    int minCameraCover(TreeNode* root) {
        auto r = getMinCover(root);
        return min(r[0], r[2]);
    }
private:
    const int MAX_INT = ~0u >> 1;
    vector<int> getMinCover(TreeNode *root) {
        vector<int> res(3, MAX_INT);
        if (!root) {
            res[0] = 0;
            return res;
        }
        auto leftRes = getMinCover(root->left);
        auto rightRes = getMinCover(root->right);
        if (leftRes[0] != MAX_INT && rightRes[2] != MAX_INT) {
            res[0] = min(res[0], leftRes[0] + rightRes[2]);
        }
        if (leftRes[2] != MAX_INT && rightRes[0] != MAX_INT) {
            res[0] = min(res[0], leftRes[2] + rightRes[0]);
        }
        if (leftRes[2] != MAX_INT && rightRes[2] != MAX_INT) {
            res[0] = min(res[0], leftRes[2] + rightRes[2]);
        }
        if (leftRes[0] != MAX_INT && rightRes[0] != MAX_INT) {
            res[1] = min(res[1], leftRes[0] + rightRes[0]);    
        }
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (leftRes[i] != MAX_INT && rightRes[j] != MAX_INT) {
                    res[2] = min(res[2], leftRes[i] + rightRes[j] + 1);
                }
            }
        }
        return res;
    }
};