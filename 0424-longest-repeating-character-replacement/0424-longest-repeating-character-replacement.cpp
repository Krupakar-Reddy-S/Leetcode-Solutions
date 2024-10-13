class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int left = 0;
        int maxLen = 0;
        int maxCount = 0;

        vector<int> count(26);

        for (int right = 0; right < n; right++) {
            count[s[right] - 'A']++;
            maxCount = max(maxCount, count[s[right] - 'A']);

            if (right - left + 1 - maxCount > k) {
                count[s[left] - 'A']--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};