#include <iostream>
#include <stack>
using namespace std;

class MinStack {
public:

    MinStack() {
        
    }
    
    void push(int val) {
        stk.push(val);
        if(minStk.empty()){
           minStk.push({val,val}); 
        }
        else{
            minStk.push({val,min(minStk.top().second, val)});
        }
    }
    
    void pop() {
        minStk.pop();
        stk.pop();
    }
    
    int top() {
       return stk.top();
    }
    
    int getMin() {
       return minStk.top().second;
    }
private:
    stack<int> stk;
    stack<pair<int,int>> minStk;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */