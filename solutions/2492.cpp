class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int,unordered_map<int,int>> graph;
        for(auto r : roads){
            graph[r[0]][r[1]] = r[2];
            graph[r[1]][r[0]] = r[2];
        }
        unordered_set<int> visited;
        int res = INT_MAX;
        return dfs(1, graph, res, visited);
    }
    int dfs(int node, unordered_map<int,unordered_map<int,int>>& graph, int & res, unordered_set<int>& vis){
        vis.insert(node);
        for(auto it = graph[node].begin(); it != graph[node].end(); it++){
            res = min(res, it->second);

            if(vis.find(it->first) != vis.end()) continue;
            res = min(res, dfs(it->first, graph, res, vis));
        }
        return res;

    }
};