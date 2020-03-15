#include "tools"
class Solution {
private:
    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (i == grid.size() || i < 0 || j == grid[0].size() || j < 0 || !grid[i][j]) return 0;
        grid[i][j] = 0;
        return 1 + dfs(grid, i - 1, j) + dfs(grid, i + 1, j) + dfs(grid, i, j - 1) + dfs(grid, i, j + 1);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j])
                    maxArea = max(maxArea, dfs(grid, i, j));
            }
        }
        return maxArea;
    }
};