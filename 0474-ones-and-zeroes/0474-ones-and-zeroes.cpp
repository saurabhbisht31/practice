class Solution {
public:
int t[601][101][101];
    int solve(vector<string>& strs, int idx, int m, int n) {

        if(idx == strs.size())
            return 0;
            if(t[idx][m][n]!=-1){
                return t[idx][m][n];
            }

        int zeroes = 0;
        int ones = 0;

        for(char ch : strs[idx]) {
            if(ch == '0')
                zeroes++;
            else
                ones++;
        }

        int take = 0;

        if(zeroes <= m && ones <= n) {
            take = 1 + solve(strs, idx + 1, m - zeroes, n - ones);
        }

        int skip = solve(strs, idx + 1, m, n);

        return t[idx][m][n]= max(take, skip);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(t , -1 , sizeof(t));
        return solve(strs, 0, m, n);
    }
};