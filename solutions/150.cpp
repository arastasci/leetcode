#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        unordered_set<string> operators = {"+","-","*","/"};
        for(int i = 0; i != tokens.size(); i++){
            if(operators.find(tokens[i])!= operators.end()){
                stk.push(calculate(tokens[i]));
            }
            else{
                stk.push(stoi(tokens[i]));
            }
        }
        return stk.top();
    }
private:
    stack<int> stk;
    int calculate(string& _operator){
        int operand2 = stk.top();
        stk.pop();
        int operand1 = stk.top();
        stk.pop();
        int result;
        if(_operator == "+"){
            result = operand1 + operand2;
        }
        else if(_operator == "-"){
            result = operand1 - operand2;
        }
        else if(_operator == "*"){
            result = operand1 * operand2;
        }
        else if(_operator == "/"){
            result = operand1 / operand2;
        }
        return result;
    }
};