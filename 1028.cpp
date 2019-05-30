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
    TreeNode* recoverFromPreorder(string S) {
        if (S == "") {
            return nullptr;
        }
        int st = S.find_first_of('-');
        if (st == string::npos) {
            st = S.length();
        }
        TreeNode *root = new TreeNode(stoi(S.substr(0, st)));
        constructTree(S, st, root, 0);
        return root;
    }
private:
    int constructTree(string &s, int p, TreeNode *node, int d) {
        while (p != s.length()) {
            int cnt = 0, q = p;
            while (s[q] == '-') {
                ++q;
                ++cnt;
            }
            if (cnt == d + 1) {
                int np = s.find_first_of('-', q);
                if (np == string::npos) {
                    np = s.length();
                }
                auto newNode = new TreeNode(stoi(s.substr(q, np - q)));
                if (node->left == nullptr) {
                    node->left = newNode;
                } else {
                    node->right = newNode;
                }
                p = constructTree(s, np, newNode, d + 1);
            } else {
                break; 
            } 
        }
        return p;
    }
};