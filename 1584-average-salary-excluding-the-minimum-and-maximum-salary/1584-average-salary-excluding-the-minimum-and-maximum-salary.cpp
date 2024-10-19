class Solution {
public:
    double average(vector<int>& salary) {
        int maxVal = salary[0];
        int minVal = salary[0];
        int n = salary.size();
        long long sum = 0L;

        for (int num : salary) {
            if (num > maxVal) {
                maxVal = num;
            }
            if (num < minVal) {
                minVal = num;
            }

            sum += num;
        }

        return (double) (sum - (maxVal + minVal)) / (n - 2);
    }
};