class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> maxHeap;

        for (int& num : nums) {
            maxHeap.push(num);
        }

        long long score = 0;

        for (int i = 0; i < k; i++) {
            int max = maxHeap.top();
            score += max;

            maxHeap.pop();
            maxHeap.push(ceil(max / 3.0));
        }

        return score;
    }
};