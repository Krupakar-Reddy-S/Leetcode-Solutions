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

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

auto __untie_cin = cin.tie(nullptr);
auto __unsync_ios_stdio = ios_base::sync_with_stdio(false);

class Solution {
public:
    void levelOrder(TreeNode* root, vector<vector<int>>& ans, int depth) {
        if (depth == ans.size()) {
            ans.push_back(vector<int>());
        }

        if (!root) {
            ans[depth].push_back(-1);
            return;
        }

        ans[depth].push_back(root->val);

        levelOrder(root->left, ans, depth+1);
        levelOrder(root->right, ans, depth+1);
    }
 
    bool isCousins(TreeNode* root, int x, int y) {
        if (root->val == x) {
            return false;
        }

        vector<vector<int>> ans;
        levelOrder(root, ans, 0);


        // for (const auto& row : ans) {
        //     for (const auto& elem : row) {
        //         cout << elem << " ";
        //     }
        //     cout << endl;
        // }

        for (int i = 1; i < ans.size(); i++) {
            for (int j = 0; j < ans[i].size(); j+=2) {
                if (ans[i][j] == x || ans[i][j+1] == x) {
                    ans[i][j] = -1;
                    ans[i][j+1] = -1;

                    for (int k = 0; k < ans[i].size(); k++) {
                        if (ans[i][k] == y) {
                            return true;
                        } 
                    }

                    return false;
                }

            }
        }
        
        return false;
    }
};