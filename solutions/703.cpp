#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int i = 0; i < nums.size(); i++){
            push_pq(nums[i]);
        }
    }
    
    int add(int val) {
        push_pq(val);
        return pq.top();
    }
private:
    priority_queue<int, vector<int>, greater<int>> pq; 
    int k;

    void push_pq(int val){
        pq.push(val);
        if(pq.size() > k) pq.pop();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */