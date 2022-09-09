#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<int>> counts;
        unordered_map<string, vector<string>> keyvalPair;
        for(int i=0; i< strs.size(); i++){
            vector<int> count(26);
            for(int j = 0; j < strs[i].size(); j++){
                count[strs[i][j] -'a']++;
            }
            string x = "";
            for(int j = 0; j < 26; j++){
                x.append(to_string(count[j]+'a'));
            }
            keyvalPair[x].push_back(strs[i]);
        }
        vector<vector<string>> res;
        for(auto el = keyvalPair.begin(); el != keyvalPair.end(); el++){
            res.push_back(el->second);
        }
        return res;
        
    }
};