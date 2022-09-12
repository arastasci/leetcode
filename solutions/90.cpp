#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int> subset;
        dfs(res, subset, nums, 0);
        return res;

    }
private:
    void dfs(vector<vector<int>>& res, vector<int>& subset, vector<int>& nums, int i){
        if(i == nums.size()){
            res.push_back(subset);
            return;
        }
        
        subset.push_back(nums[i]);
        dfs(res, subset, nums, i+1);
        subset.pop_back();
        while(i+1 !=  nums.size() && nums[i] == nums[i+1]) i++;
        dfs(res, subset, nums, i+1);

    }
};