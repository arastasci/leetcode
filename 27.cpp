#include <vector>
#include <iostream>
using namespace std;

class Solution{
public:
    int removeElement(vector<int>& nums, int val) {
        int ind = 0;
        for(int i = 0; i != nums.size(); i++){
            if(nums[i] != val){
                nums[ind++] = nums[i];
            }
        }
        return ind;
    }
};