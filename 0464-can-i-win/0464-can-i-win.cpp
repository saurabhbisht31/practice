class Solution {
public:

    unordered_map<int, bool> dp;

    bool solve(int mask, int remaining, int n) {

        if(dp.count(mask))
            return dp[mask];

        for(int num = 1; num <= n; num++) {

            int bit = 1 << (num - 1);

            if(mask & bit)
                continue;

            if(num >= remaining)
                return dp[mask] = true;

            int newMask = mask | bit;

            if(!solve(newMask, remaining - num, n))
                return dp[mask] = true;
        }

        return dp[mask] = false;
    }

    bool canIWin(int maxChoosableInteger, int desiredTotal) {

        int total = maxChoosableInteger *
                    (maxChoosableInteger + 1) / 2;

        if(total < desiredTotal)
            return false;

        return solve(0, desiredTotal, maxChoosableInteger);
    }
};