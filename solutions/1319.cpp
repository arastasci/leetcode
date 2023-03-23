
class DisjointSet{
public:
    int parent[100000];
    DisjointSet(int n){
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }
    int findParent(int v){
        if(parent[v] == v){
            return v;
        }
        return findParent(parent[v]);
    }
    void unionFunc(int a, int b){
        int parA = findParent(a);
        int parB = findParent(b);
        if(parA != parB){
            parent[parA] = parB;
        }
    }
    bool isInSameSet(int a, int b){
        return findParent(a) == findParent(b);
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int redundantConnection = 0;
        int numberOfSets = n;
        for(int i = 0; i < connections.size(); i++){
            int a = connections[i][0];
            int b = connections[i][1];
            if(!ds.isInSameSet(a,b)){
                ds.unionFunc(a,b);
                numberOfSets--;
            }
            else{
                redundantConnection++;
            }
        }
        if(numberOfSets-1 > redundantConnection){
            return -1;
        }
        return numberOfSets-1;
        
       
        
            
        
    }
    
};