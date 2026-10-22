
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;

        int k = 0;
        while (nums[k] != 0) {
            k++;
        }

        bool ok = true;

        for (int i = 0; i < n; i++) {
            if (nums[(k + i) % n] != i) {
                ok = false;
                break;
            }
        }

        if (ok) {
            ans = min(k, n - k + 2);
        }

        k = 0;
        while (nums[k] != n - 1) {
            k++;
        }

        ok = true;

        for (int i = 0; i < n; i++) {
            if (nums[(k + i) % n] != n - 1 - i) {
                ok = false;
                break;
            }
        }

        if (ok) {
            ans = min(ans, min(k + 1, n - k + 1));
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
