#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        this->target = target;
        vector<int> combination;
        dfs(candidates, combination);
        return res;
    }
private:
    int target{};
    vector<vector<int>> res;
    void dfs(vector<int>& candidates, vector<int>& combination, int prevSum = 0, int i = 0){        
        if(prevSum == target){
            res.push_back(combination);
            return;
        }
        if(prevSum > target || i >= candidates.size()){
            return;
        }
        combination.push_back(candidates[i]);
        dfs(candidates, combination, prevSum + candidates[i], i);
        combination.pop_back();
        dfs(candidates, combination, prevSum, i+1);
    }
};