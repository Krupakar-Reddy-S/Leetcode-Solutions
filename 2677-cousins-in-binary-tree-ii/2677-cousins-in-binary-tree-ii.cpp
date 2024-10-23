/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int levelSum[100000] = {0};

    TreeNode* replaceValueInTree(TreeNode* root) {
        helper(root, 0);

        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        root->val = 0;
        int level = 1;

        while (!q.empty()) {
            int size = q.size();
            vector<pair<TreeNode*, int>> nodes;

            for (int i = 0; i < size; i++) {
                TreeNode* cur = q.front().first;
                int parentVal = q.front().second;
                q.pop();

                int bro = 0;
                
                if (cur->left) {
                    bro += cur->left->val;
                }
                if (cur->right) {
                    bro += cur->right->val;
                }

                nodes.push_back({cur, bro});
            }

            for (auto& p : nodes) {
                TreeNode* parent = p.first;
                int bro = p.second;

                if (parent->left) {
                    q.push({parent->left, bro});
                    parent->left->val = levelSum[level] - bro;
                }
                if (parent->right) {
                    q.push({parent->right, bro});
                    parent->right->val = levelSum[level] - bro;
                }
            }

            level++;
        }

        return root;
    }

    void helper(TreeNode* node, int level) {
        if (!node) {
            return;
        }

        levelSum[level] += node->val;

        helper(node->left, level + 1);
        helper(node->right, level + 1);
    }
};