class Solution {
public:
    vector<vector<int>> dp;

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        dp = vector<vector<int>>(n + 1, vector<int>(n + 1, -1));

        return helper(nums, 0, -1);
    }

    int helper(vector<int>& nums, int idx, int prevIdx) {
        if (idx == nums.size()) {
            return 0;
        }

        if (dp[idx][prevIdx + 1] != -1) {
            return dp[idx][prevIdx + 1];
        }

        int ans1 = helper(nums, idx + 1, prevIdx);
        int ans2 = 0;

        if (prevIdx == -1 || nums[idx] > nums[prevIdx]) {
            ans2 = 1 + helper(nums, idx + 1, idx);
        }

        return dp[idx][prevIdx + 1] = max(ans1, ans2);
    }
};