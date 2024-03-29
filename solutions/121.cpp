#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxP = 0;
        for(int i = 1; i < prices.size(); i++){
           
            minPrice = min(minPrice, prices[i]);
            maxP = max(prices[i] - minPrice, maxP);
        }
        return maxP;

    }
};