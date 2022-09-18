#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> m(numCourses);
        for(int i = 0; i < prerequisites.size(); i++){
            m[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        unordered_set<int> visited;
        unordered_set<int> added;
        vector<int> res;
        for(int i = 0; i < numCourses; i++){
            if(!dfs(m, visited, added, res,i)){
                return {};
            }
        }
        return res;
    }
private:
    bool dfs(unordered_map<int,vector<int>>& m, unordered_set<int>& visited,unordered_set<int>& added, vector<int>& res, int course){
        if(visited.find(course) != visited.end()){
            return false;
        }
        if(added.find(course) != added.end()){
            return true;
        }
        visited.insert(course);
        for(int i = 0; i < m[course].size(); i++){
            if(!dfs(m, visited, added, res, m[course][i])){
                return false;
            }
        }
        visited.erase(course);
        m[course].clear();
        
        res.push_back(course);
        added.insert(course);
        
        return true;

    }
};