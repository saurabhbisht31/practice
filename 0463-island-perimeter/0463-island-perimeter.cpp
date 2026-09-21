class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        int adj = 0;
        int yeno = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(grid[i][j] == 1) {

                    yeno++;

         if(i + 1 < n && grid[i+1][j] == 1)
                        adj++;

        if(j + 1 < m && grid[i][j+1] == 1)
                        adj++;
                }
            }
        }

        return yeno * 4 - adj * 2;
    }
};