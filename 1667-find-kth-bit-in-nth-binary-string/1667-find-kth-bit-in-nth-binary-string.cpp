class Solution {
public:
    char findKthBit(int n, int k) {
        string num = "0";
        
        for (int i = 1; i < n; i++) {
            num = num + "1" + helper(num);
        }

        return num[k - 1];
    }

    string helper(string num) {
        int n = num.length();

        for (int i = 0; i < n; i++) {
            num[i] = num[i] == '0' ? '1' : '0';
        }

        for (int i = 0; i < n / 2; i++) {
            swap(num[i], num[n - 1 - i]);
        }

        return num;
    }
};