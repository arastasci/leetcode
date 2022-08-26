#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = -1;
        int maxVal = 0;
        vector<int> lastSeen(128,-1);
        for(int right = 0; right < s.size(); right++){
            if(left < lastSeen[s[right]]){
                left = lastSeen[s[right]];
            }
            lastSeen[s[right]] = right;
            maxVal = max(maxVal, right - left);
            
        }
        return maxVal;
    }
};