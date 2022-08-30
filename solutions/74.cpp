#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int lowRow = 0;
        int highRow = matrix.size() - 1;
        int dLength = matrix[0].size() - 1;
        bool flag = false;
        while(lowRow < highRow){
            int mid = (lowRow + highRow) / 2;
            if(matrix[mid][0] > target){
                highRow = mid - 1;
            }
            if(matrix[mid][0] < target && target < matrix[mid+1][0]){
                lowRow = mid;
                break;
            }
            if(matrix[mid][0] < target && target >= matrix[mid+1][0]){
                lowRow = mid + 1;
                
            }
             if(matrix[mid][0] == target){
                 return true;
             }
        }
        int lowCol = 0;
        int highCol = dLength;
        while (lowCol <= highCol)
        {
            int midCol = lowCol + (highCol - lowCol) / 2;
            if(matrix[lowRow][midCol] > target){
                highCol = midCol - 1;
            }
            else if(matrix[lowRow][midCol] < target){
                lowCol = midCol + 1;
            }
            else return true;
        }
        return false;
        
    }
};


