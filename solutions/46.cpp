#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums, 0);
        return res;
    }

private:
    vector<vector<int>> res;
    void dfs(vector<int>& nums, int start){
        if(start == nums.size()){
            res.push_back(nums);
            return;
        }
        for(int j = start; j < nums.size(); j++){
            std:swap(nums[start],nums[j]);
            dfs(nums, j+1);
            std::swap(nums[start], nums[j]);
        }
    }
};