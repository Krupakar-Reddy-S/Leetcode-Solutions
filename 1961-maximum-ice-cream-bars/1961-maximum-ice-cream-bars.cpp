class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int count = 0;
        sort(costs.begin(), costs.end());

        for (int cost : costs) {
            if (cost > coins) {
                break;
            }

            coins -= cost;
            count++;
        }

        return count;
    }
};