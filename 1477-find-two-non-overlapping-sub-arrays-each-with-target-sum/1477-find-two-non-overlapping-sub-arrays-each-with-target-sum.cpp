class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {

        int n = arr.size();

        vector<int> best(n, INT_MAX);

        int left = 0;
        int right = 0;

        int bestm = INT_MAX;
        int sum = 0;
        int ans = INT_MAX;

        while (right < n) {

            sum += arr[right];

     while (sum > target) {
                sum -= arr[left];
                left++;
            }

            if (sum == target) {

                int len = right - left + 1;

       if (left > 0 && best[left - 1] != INT_MAX) {
                    ans = min(ans, best[left - 1] + len);
                }

 bestm = min(bestm, len);
            }

 best[right] = bestm;

            right++;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};