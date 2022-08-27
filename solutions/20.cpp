#include <iostream>
// #include <string>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> myStack;
        unordered_map<char, char> complement = {{'{','}'},{'(',')'},{'[',']'}};
        for(int i = 0; i < s.size(); i++){
            if(complement.find(s[i]) != complement.end()){
                myStack.push(s[i]);
            }
            else if(!myStack.empty() && complement[myStack.top()] == s[i]){
                myStack.pop();
            }
            else{
                return false;
            }
        }
        return myStack.empty();
    }
};