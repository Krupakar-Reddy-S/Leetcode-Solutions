class Solution {
public:
    long long minimumSteps(string s) {
        long long count = 0L;
        int n = s.length();
        
        int ones = 0;

        for (char ch : s) {
            if (ch == '1') {
                ones++;
            }
        }

        int zeroes = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') {
                zeroes++;
            }
            else {
                count += zeroes;
            }
        }

        return count;
    }
};