class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxSize = 0;
        int start = 0;
        unordered_set<char> set;

        for (int i = 0; i < s.length(); i++) {
            char curChar = s[i];

            while (set.count(curChar)) {
                set.erase(s[start]);
                start++;
            }

            set.insert(curChar);

            maxSize = max(maxSize, i - start + 1);
        }

        return maxSize;
    }
};