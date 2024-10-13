class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return solve(nums, 0, nums.size() - 1);
    }

    int solve(vector<int>& nums, int start, int end) {
        if (start >= end) {
            return 0;
        }

        int mid = start + (end - start) / 2;

        int ans1 = solve(nums, start, mid);
        int ans2 = solve(nums, mid + 1, end);

        int ans3 = merge(nums, start, mid, end);

        return ans1 + ans2 + ans3;
    }

    int merge(vector<int>& nums, int start, int mid, int end) {
        int count = 0;

        int j = mid + 1;
        for (int i = start; i <= mid; i++) {
            while (j <= end && nums[i] > 2L * nums[j]) {
                j++;
            }
            
            count += (j - (mid + 1));
        }

        vector<int> temp;
        int left = start, right = mid + 1;

        while (left <= mid && right <= end) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left]);
                left++;
            }
            else {
                temp.push_back(nums[right]);
                right++;
            }
        }

        while (left <= mid) {
            temp.push_back(nums[left]);
            left++;
        }

        while (right <= end) {
            temp.push_back(nums[right]);
            right++;
        }

        for (int i = start; i <= end; i++) {
            nums[i] = temp[i - start];
        }

        return count;
    }
};