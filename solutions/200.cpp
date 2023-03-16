#include <vector>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int result = 0;
        for(int i = 0 ; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    dfs(grid, i, j);
                    result++;
                }
            }
        }
        return result;
    }
private:
    void dfs(vector<vector<char>>& grid, int y, int x){
        if( x < 0 || y < 0 || x == grid[0].size() || y == grid.size() ||   grid[y][x] == '0') return;

        grid[y][x] = '0';

        dfs(grid, y+1, x);
        dfs(grid, y-1, x);
        dfs(grid, y, x+1);
        dfs(grid, y, x-1);
    }
};