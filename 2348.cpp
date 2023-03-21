class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
    
        int i = 0;
        int j = 0;
        long long totalAmount = 0;
        while(j < nums.size()){
            if(nums[j] == 0){
                j++;
            }
            else{
                if(i != j){
                    long long n = j-i;
                    totalAmount += (n*(n+1)) / 2;
                }
                j++;
                i = j;
            }
        }
        if(i != j){
            long long n = j-i;
            totalAmount += (n*(n+1)) / 2;
        }
        
        return totalAmount;
    }
};