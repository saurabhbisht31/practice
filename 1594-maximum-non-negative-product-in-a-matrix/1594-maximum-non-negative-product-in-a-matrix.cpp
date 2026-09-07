class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<long long>> maxi(
            m, vector<long long>(n, LLONG_MIN)
        );

        vector<vector<long long>> mini(
            m, vector<long long>(n, LLONG_MAX)
        );

        maxi[0][0] = grid[0][0];
        mini[0][0] = grid[0][0];

        for (int j = 1; j < n; j++) {
            maxi[0][j] = maxi[0][j - 1] * grid[0][j];
            mini[0][j] = maxi[0][j];
        }

        for (int i = 1; i < m; i++) {
            maxi[i][0] = maxi[i - 1][0] * grid[i][0];
            mini[i][0] = maxi[i][0];
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {

                long long a = maxi[i - 1][j] * grid[i][j];
                long long b = mini[i - 1][j] * grid[i][j];
                long long c = maxi[i][j - 1] * grid[i][j];
                long long d = mini[i][j - 1] * grid[i][j];

                maxi[i][j] = max({a, b, c, d});
                mini[i][j] = min({a, b, c, d});
            }
        }

        if (maxi[m - 1][n - 1] < 0)
            return -1;

        return maxi[m - 1][n - 1] % 1000000007;
    }
};