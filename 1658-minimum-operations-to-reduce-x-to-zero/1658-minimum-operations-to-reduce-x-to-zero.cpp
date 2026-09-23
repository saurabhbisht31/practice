class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        long long total = 0;

        for (int i = 0; i < n; i++) {
            total += nums[i];
        }

        long long rem = total - x;

        if (rem < 0) {
            return -1;
        }

        long long sum = 0;

        int left = 0;
        int maxLen = -1;

        for (int right = 0; right < n; right++) {

            sum += nums[right];

            while (sum > rem) {
                sum -= nums[left];
                left++;
            }

            if (sum == rem) {
                int len = right - left + 1;
                maxLen = max(maxLen, len);
            }
        }

        if (maxLen == -1) {
            return -1;
        }

        return n - maxLen;
    }
};