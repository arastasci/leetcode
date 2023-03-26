class Solution1 {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        int step = 0;
        int ans = -1;
        vector<int> distance(n, -1);
        unordered_set<int> visited;
        
        for(int i = 0; i < n; i++) {
            if(!visited.count(i)) {
                int start = step;
                int node = i;
                
                while(node != -1) {
                    step++;
                    distance[node] = step;
                    visited.insert(node);
                    node = edges[node];
                    
                    if(visited.count(node)) {
                        if(distance[node] > start) {
                            ans = max(ans, step - distance[node] + 1);
                        }
                        break;
                    }
                }
            }
        }
        return ans;
    }
};

class Solution2 {
public:
    int longestCycle(vector<int>& edges) {
        const int n = edges.size();
        int ans = -1, time = 1;
        vector<int> timeVisited(n);

        for (int i = 0; i < n; ++i){
            if (timeVisited[i] > 0){
                continue;
            }

            const int startTime = time;
            int j = i;
            while (j >= 0 && timeVisited[j] == 0){
                timeVisited[j] = time++;
                j = edges[j];
            }

            if (j != -1 && timeVisited[j] >= startTime){
                ans = max(ans, time - timeVisited[j]);
            }
        }

        return ans;
    }
};