#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> heap;
        for(int i = 0; i < stones.size(); i++){
            heap.push(stones[i]);
        }
        while(heap.size() > 1){
            int y = heap.top();
            heap.pop();
            int x = heap.top();
            heap.pop();
            if(x < y){
                heap.push(y-x);
            }            
        }
        if(heap.size())
        return heap.top();
        else return 0;
    }
    
};