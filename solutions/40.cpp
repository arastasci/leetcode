#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution1 {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res{};
        vector<int> combination{};
        dfs(candidates, res, combination, 0, target);
        return res;
    }
private:
    void dfs(vector<int>& candidates, vector<vector<int>>& res, vector<int> combination, int i,int target){
        if(target == 0) {
            res.push_back(combination);
            return;
        }
        if(target < 0 || i == candidates.size()) return;

        combination.push_back(candidates[i]);
        dfs(candidates, res, combination,  i+1, target - candidates[i]);

        combination.pop_back();
        while( i+1 != candidates.size() && candidates[i] == candidates[i+1]) i++;
        dfs(candidates, res, combination, i+1, target);

    }
};

class Solution2{
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res{};
        vector<int> combination{};
        dfs(candidates, res, combination, 0, target);
        return res;
    }

private:
    void dfs(vector<int>& candidates, vector<vector<int>>& res, vector<int> combination, int start,int target){
        if(target == 0) {
            res.push_back(combination);
            return;
        }
        if( target < 0) return;
        int prev = -1;
        for(int i = start; i < candidates.size(); i++){
            if(candidates[i] == prev) continue;
            combination.push_back(candidates[i]);
            dfs(candidates, res, combination, i+1, target - candidates[i]);
            combination.pop_back();
            prev = candidates[i];
        }


    }
};