class Solution {
public:
    int reverseDegree(string s) {
        int n = s.length();
        int sum = 0;

        for (int i = 0; i < n; i++) {
            int value = 'z' - s[i] + 1;
            int idx = i + 1;

            sum += value * idx;
        }

        return sum;
    }
};