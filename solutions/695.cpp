#include <vector>
using namespace std;


class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int curMax = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] ==1)
                curMax = max(dfs(grid, i, j),curMax);
            }
        }
        return curMax;
    }
public:
    int dfs(vector<vector<int>>& grid, int y, int x){
        if(y < 0 || x < 0 || y == grid.size() || x == grid[0].size() || grid[y][x] ==0){
            return 0;
        }
        grid[y][x] = 0;

        int result = 1;
        result += dfs(grid, y+1, x);
        result += dfs(grid, y-1, x);
        result += dfs(grid, y, x+1);
        result += dfs(grid, y, x-1);

        return result;

    }
};