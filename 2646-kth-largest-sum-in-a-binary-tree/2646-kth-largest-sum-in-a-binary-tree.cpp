/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> level;
        
        helper(root, level, 0);

        if (level.size() < k) {
            return -1;
        }

        sort(level.begin(), level.end());

        // for (int num : level) {
        //     cout << num << " ";
        // }

        return level[level.size() - k];
    }

    void helper(TreeNode* root, vector<long long>& level, int depth) {
        if (!root) {
            return;
        }

        if (depth == level.size()) {
            level.push_back(0LL);
        }

        level[depth] += root->val;

        helper(root->left, level, depth + 1);
        helper(root->right, level, depth + 1);
    }
};