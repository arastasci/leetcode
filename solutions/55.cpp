#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int distance = 1;
        int n = nums.size();
        int lastIndex = n -1;
        for(int i = n -2; i >= 0; i--){
            if(nums[i]>= distance){
                lastIndex = i;
                distance = 1;
            }
            else{
                distance++;
            }
        }
        if(lastIndex == 0) return true;
        return false;
    }
};