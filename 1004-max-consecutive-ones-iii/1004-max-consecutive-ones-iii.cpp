class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int zeroes = 0;
        int maxLen = 0;

        for (int right = 0; right < n; right++) {
            if (nums[right] == 0) {
                zeroes++;
            }

            while (zeroes > k) {
                if (nums[left] == 0) {
                    zeroes--;
                }

                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};