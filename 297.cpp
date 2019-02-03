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
        if (!root) {
            return "#,";
        }
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stack<pair<TreeNode *, int>> s;
        TreeNode *root = nullptr, *now = nullptr;
        int start = 0, p = -1;
        while ((p = data.find(",", start)) != string::npos) {
            string sv = data.substr(start, p - start);
            start = p + 1;
            if (sv == "#") {
                if (s.empty()) {
                    return nullptr;
                } else {
                    if (s.top().second == 1) {
                        s.top().second = 0;
                    } else {
                        s.pop();
                    }
                } 
            } else {
                int v = stoi(sv);
                auto p = new TreeNode(v);
                if (s.empty()) {
                    root = p;
                    s.push({p, 1});
                } else {
                    if (s.top().second == 1) {
                        s.top().second = 0;
                        s.top().first->left = p;
                    } else {
                        s.top().first->right = p;
                        s.pop();
                    }
                    s.push({p, 1});
                }
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));