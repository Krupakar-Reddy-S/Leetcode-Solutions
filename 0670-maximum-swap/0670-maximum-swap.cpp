class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        int maxNum = num;
        int n = str.length();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(str[i], str[j]);
                int newNum = stoi(str);

                if (newNum > maxNum) {
                    maxNum = newNum;
                }
                
                swap(str[i], str[j]);
            }
        }

        return maxNum;
    }
};