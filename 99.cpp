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
    void recoverTree(TreeNode* root) {
        if (!root) {
            return;
        }
        vector<TreeNode *> treeSeq;
        getTreeSeq(root, treeSeq);
        auto expectSeq = treeSeq;
        sort(expectSeq.begin(), expectSeq.end(), [](auto a, auto b) -> bool {return (a->val < b->val);});
        int first = -1, second = -1;
        for (int i = 0; i < treeSeq.size(); ++i) {
            if (treeSeq[i] != expectSeq[i]) {
                if (first == -1) {
                    first = i;
                } else {
                    second = i;
                }
            }
        }
        swap(treeSeq[first]->val, treeSeq[second]->val);
    }
private:
    void getTreeSeq(TreeNode *root, vector<TreeNode *> &treeSeq) {
        if (!root) {
            return; 
        }
        getTreeSeq(root->left, treeSeq);
        treeSeq.push_back(root);
        getTreeSeq(root->right, treeSeq);
    }
};

