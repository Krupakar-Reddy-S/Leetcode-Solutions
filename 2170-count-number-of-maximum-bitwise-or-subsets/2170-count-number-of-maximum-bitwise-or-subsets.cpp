class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        vector<vector<int>> subsets;
        vector<int> temp;
        helper(nums, subsets, temp, 0);

        vector<int> ors;
        int maxOr = 0;

        for (vector<int>& subset : subsets) {
            int Or = 0;

            for (int num : subset) {
                Or |= num;
            }

            ors.push_back(Or);

            if (maxOr < Or) {
                maxOr = Or;
            }
        }

        int count = 0;

        for (int Or : ors) {
            if (Or == maxOr) {
                count++;
            }
        }

        return count;
    }

    void helper(vector<int>& nums, vector<vector<int>>& subsets, vector<int>& temp, int index) {
        subsets.push_back(temp);

        for (int i = index; i < nums.size(); i++) {
            temp.push_back(nums[i]);
            helper(nums, subsets, temp, i + 1);
            temp.pop_back();
        }
    }
};