#include <vector>
#include <string>

using namespace std;



/*
    Another option would be to use a set to keep track of coordinates of visited tiles.
*/
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        const int width = board[0].size();
        const int height = board.size();
        
        for(int i = 0; i < height; i++){
            for(int j = 0; j < width; j++){
                vector<vector<bool>> visitedBoard;
                visitedBoard.resize(height,vector<bool>(width));
                for(int k = 0; k < width; k++){
                    for(int m = 0; m < height; m++){
                        visitedBoard[m][k] = false;
                    }
                }

                bool flag = dfs(board, visitedBoard, word, 0, j , i);
                if(flag) return true;
            }
        }
        return false;
    }
private:
    bool dfs(vector<vector<char>>& board,vector<vector<bool>>& visitedBoard, string& word, int index, int x, int y){
        if(word[index] != board[y][x])
        return false;
        if(index == word.size()-1) return true;
        visitedBoard[y][x] = true;
        bool flags[4] = {false, false, false, false};
        if(x+1 < board[0].size()&& !visitedBoard[y][x+1]){
           flags[0] = dfs(board, visitedBoard, word, index+1 , x+1, y);
        }
        if(x-1 >= 0 && !visitedBoard[y][x-1] ){
           flags[1] = dfs(board, visitedBoard, word, index+1, x-1, y);
        }
        if(y+1 < board.size() && !visitedBoard[y+1][x]){
           flags[2] = dfs(board, visitedBoard, word, index+1, x, y+1);
        }
        if(y-1 >= 0 && !visitedBoard[y-1][x]){
           flags[3] = dfs(board, visitedBoard, word, index+1 , x, y-1);
        }
        if(!(flags[0] || flags[1] || flags[2] || flags[3])){
            visitedBoard[y][x] = false;
            return false;
        }
        else return true;
    }
};


class Solution2{
public:
    bool exist(vector<vector<char>>& board, string word) {
        const int width = board[0].size();
        const int height = board.size();
        
        for(int i = 0; i < height; i++){
            for(int j = 0; j < width; j++){
                if(dfs(board, word, 0, j , i))
                 return true;
            }
        }
        return false;
    }
private:
    bool dfs(vector<vector<char>>& board,string& word, int index, int x, int y){
        if(index == word.size()) return true;
        else if(x<0 || y<0 || x >= board[0].size() || y >= board.size() || word[index] != board[y][x]) return false;
        char og = board[y][x];
        board[y][x] = '#';
        if(dfs(board, word, index, x+1, y)){
            return true;
        }
        if(dfs(board, word, index, x-1, y)){
            return true;
        }
        if(dfs(board, word, index, x, y+1)){
            return true;
        }
        if(dfs(board, word, index, x+1, y-1)){
            return true;
        }
        board[y][x] = og;
        return false;
    }

};