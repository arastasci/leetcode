#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> integers;
        unordered_set<string> operators = {"+","-","/", "*"};

        for(int i = 0; i < tokens.size(); i++){
            if(operators.find(tokens[i])!=operators.end()){
                int operand2 = integers.top();
                integers.pop();
                int operand1 = integers.top();
                integers.pop();
                integers.push(calculate(tokens[i], operand1, operand2));
            }
            else {
                integers.push(stoi(tokens[i]));
            }
        }
        return integers.top();
    }
private:
    int calculate(string token, int operand1, int operand2){
        if(token =="+"){
            return operand1 + operand2;
        }

        else if(token =="-"){
            return operand1 - operand2;
        }
        else if(token =="/"){
            return operand1 / operand2;
        }
        else{
            return operand1 * operand2;
        }
    }
};