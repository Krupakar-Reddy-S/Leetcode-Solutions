class Solution {
public:
    int maxSize = 0;
    int n;

    int maxUniqueSplit(string s) {
        n = s.length();
        helper(s, 0, unordered_set<string>());

        return maxSize;
    }

    void helper(string s, int start, unordered_set<string> set) {
        if (start == n) {
            maxSize = max(maxSize, (int) set.size());
            return;
        }

        for (int end = start + 1; end <= n; end++) {
            string sub = s.substr(start, end - start);

            if (!set.count(sub)) {
                set.insert(sub);
                helper(s, end, set);
                set.erase(sub);
            }
        }
    }
};