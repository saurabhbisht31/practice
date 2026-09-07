class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> t(m, vector<int>(n, 0));

   
        if (obstacleGrid[0][0] == 1)
            return 0;

        t[0][0] = 1;
        for (int col = 1; col < n; col++) {
            if (obstacleGrid[0][col] == 1) {
                t[0][col] = 0;
            }
            else {
                t[0][col] = t[0][col - 1];
            }
        }
        for (int row = 1; row < m; row++) {
            if (obstacleGrid[row][0] == 1) {
                t[row][0] = 0;
            }
            else {
                t[row][0] = t[row - 1][0];
            }
        }
        for (int row = 1; row < m; row++) {
            for (int col = 1; col < n; col++) {

                if (obstacleGrid[row][col] == 1) {
                    t[row][col] = 0;
                }
                else {
                    t[row][col] =
                        t[row - 1][col] + t[row][col - 1];
                }
            }
        }

        return t[m - 1][n - 1];
    }
};