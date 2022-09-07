#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,vector<int>>> heap;
        
        for(int i = 0 ; i < points.size(); i++){
            double dist = pow(points[i][0],2) + pow(points[i][1],2);
            heap.push({dist,points[i]});
            if(heap.size()>k) heap.pop();
        }
        vector<vector<int>> res;
        while(!heap.empty()){
            res.push_back(heap.top().second);  
            heap.pop();
        }
        return res;
    }
};