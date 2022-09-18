#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> m(numCourses);
        for(int i = 0; i < prerequisites.size(); i++){
            m[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        unordered_set<int> visited;
        
        for(int i = 0; i < numCourses; i++){
            if(!dfs(m, visited, i)){
                return false;
            }
        }
        return true;
    }
private:
    bool dfs(unordered_map<int,vector<int>>& m, unordered_set<int>& visited, int course){
        if(visited.find(course) != visited.end()){
            return false;
        }
        if(m[course].empty()){
            return true;
        }
        visited.insert(course);
        for(int i = 0; i < m[course].size(); i++){
           if(!dfs(m, visited, m[course][i])){
                return false;
           }
        }
        visited.erase(course);
        m[course].clear();
        return true;

    }
};