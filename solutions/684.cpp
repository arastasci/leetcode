#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
       int n = edges.size();
       vector<int> parents(n+1);
       vector<int> ranks(n+1);

       for(int i = 0; i < n+1; i++){
        parents[i] = i;
        ranks[i] = 1;
       }

       for(int i = 0; i < n; i++){
        int n1 = edges[i][0];
        int n2 = edges[i][1];
        if(!doUnion(parents, ranks, n1, n2)){
            return {n1, n2};
        }
       }
       return {};

    }
private:
    int find(vector<int>& parents, int n){
        int p = parents[n];
        while(p != parents[p]){
            parents[p] = parents[parents[p]];
            p = parents[p];
        }
        return p;
    }
    bool doUnion(vector<int>& parents, vector<int> &ranks, int n1, int n2){
        int p1 = find(parents, n1);
        int p2 = find(parents, n2);

        if(p1 == p2){
            return false;
        }

        if(ranks[p1] > ranks[p2]){
            parents[p2] = p1;
            ranks[p1] += ranks[p2];
        }
        else{
            parents[p1] = p2;
            ranks[p2] += ranks[p1];
        }
        return true;
    }
};