class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> maxHeap;

        if (a > 0) maxHeap.push({a, 'a'});
        if (b > 0) maxHeap.push({b, 'b'});
        if (c > 0) maxHeap.push({c, 'c'});

        string ans;

        while (!maxHeap.empty()) {
            auto top = maxHeap.top();
            maxHeap.pop();

            if (ans.size() >= 2 && ans[ans.size() - 1] == top.second && ans[ans.size() - 2] == top.second) {
                if (maxHeap.empty()) break;

                auto nextTop = maxHeap.top();
                maxHeap.pop();

                ans += nextTop.second;
                nextTop.first--;

                if (nextTop.first > 0) {
                    maxHeap.push(nextTop);
                }

                maxHeap.push(top);
            }
            else {
                ans += top.second;
                top.first--;

                if (top.first > 0) {
                    maxHeap.push(top);
                }
            }
        }

        return ans;
    }
};