class Solution {
public:

    int t[201][20001];

    bool solve(vector<int>& nums, int i, int Tsum, int sum) {
        if(sum == Tsum - sum) {
            return true;
        }

        if(i == nums.size()) {
            return false;
        }

        if(t[i][sum] != -1) {
            return t[i][sum];
        }

        bool take = solve(nums, i + 1, Tsum, sum + nums[i]);

   
        bool skip = solve(nums, i + 1, Tsum, sum);

        return t[i][sum] = take || skip;
    }

    bool canPartition(vector<int>& nums) {

        int Tsum = 0;

        for(int x : nums) {
            Tsum += x;
        }
        if(Tsum % 2 != 0) {
            return false;
        }

        memset(t, -1, sizeof(t));

        return solve(nums, 0, Tsum, 0);
    }
};