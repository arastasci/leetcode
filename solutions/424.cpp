#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26);
        int left = 0;
        int maxC = 0;
        int longestSubS = 0;
        for(int right = 0; right != s.size(); right++){
            count[s[right]- 'A']++;
            maxC = max(maxC, count[s[right] - 'A']);
            if((right - left + 1) - k > maxC){
                count[s[left] - 'A']--;
                left++;
            }
            longestSubS = max(longestSubS,  right - left + 1);
        }
        return longestSubS;
    }
};