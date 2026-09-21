class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();

        vector<long long> result(k, 0);
        vector<long long> prevcount(k, 0);

        for (int i = 0; i < n; i++) {

            vector<long long> currCount(k, 0);
            int rem = nums[i] % k;
            currCount[rem]++;
            for (int old = 0; old < k; old++) {

                int newrem = ((long long)old * nums[i]) % k;

                currCount[newrem] += prevcount[old];
            }
            for (int r = 0; r < k; r++) {
                result[r] += currCount[r];
            }
            prevcount = currCount;
        }

        return result;
    }
};