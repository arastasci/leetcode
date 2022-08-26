#include <iostream>
#include <vector>

using namespace std;
class Solution{
  public:
    bool isPalindrome(string s){
        string str;
        for(int i = 0; i < s.size(); i++){
            if(isalnum(s.at(i))){
                str+= (tolower(s.at(i)));
            }
        }
        int size = str.size();
        int iteration = size / 2;
        for(int i = 0; i < iteration; i++){
            if(str[i] != str[size-i-1]){
                return false;
            }
        }
        return true;
    }
};