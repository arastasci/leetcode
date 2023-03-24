class Solution {
public:
    
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int,vector<int>> adjList(n);
        unordered_map<int,vector<int>> reverseAdjList(n);
        for(auto& edge : connections){
            adjList[edge[0]].push_back(edge[1]);
            reverseAdjList[edge[1]].push_back(edge[0]);
        }
        vector<bool> canReach(n, false);    
        int ans = 0;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int cur = q.front();
            canReach[cur] = true;
            q.pop();
            for(int adj : adjList[cur]){
                if(canReach[adj]) continue;
                ans++;
                q.push(adj);
            }
            for(int adj : reverseAdjList[cur]){
                if(canReach[adj]) continue;
                q.push(adj);
            }
        }
        return ans;

    }
    
   


    
};