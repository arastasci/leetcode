#include <vector> 
#include <queue>
using namespace std;

/*
bfs ile rotla,
rotladiktan sonra fresh kalmış mı diye bak,
eğer prevFresh == şu anki fresh sayısı return -1;



0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
*/


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;

        int m = grid.size();
        int n = grid[0].size();
        int fresh = 0;
        int time = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }

        while(fresh > 0  && !q.empty()){
            int len = q.size();
            for(int k = 0; k < len; k++){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                for(int el = 0; el < dirs.size(); el++){
                    int row = i + dirs[el][0];
                    int col = j + dirs[el][1];
                    if(row < 0 || col < 0 || row == m || col == n){
                        continue;
                    }
                    if(grid[row][col] == 1){
                        grid[row][col] = 2;
                        q.push({row,col});
                        fresh--;
                    }
                }

            }
            time++;
            
        }
        if(fresh == 0){
            return time;
        }   
        return -1;
    }
private:
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
};