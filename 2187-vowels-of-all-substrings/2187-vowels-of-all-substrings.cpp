class Solution {
public:
    long long countVowels(string word) {
        long long count = 0LL;
        int n = word.length();

        for (int i = 0; i < n; i++) {
            char ch = word[i];
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                count += ((long long)(n - i) * (i + 1));
            }
        }

        return count;
    }
};