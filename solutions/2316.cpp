class Solution {
public:    
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        for(int i = 0; i < edges.size(); i++){
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }
        unordered_set<int> visited(n);
        vector<long long> setsElementCount;
        long long res = ((long long) n*(n-1))/2;


        for(int i = 0; i< adjList.size(); i++){
            if(visited.count(i)) continue;
            long long count = dfs(i, adjList, visited);
            res -= count * (count - 1) / 2;
        }
        return res;
    }
    int dfs(int node, vector<vector<int>>& adjList, unordered_set<int>& visited){
        visited.insert(node);
        int res = 0;
        for(int i = 0; i < adjList[node].size(); i++){
            if(visited.count(adjList[node][i]) != 0) continue;
            res += dfs(adjList[node][i], adjList, visited);
        }
        return res + 1;
    }
};