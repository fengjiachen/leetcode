//
//  main.cpp
//  155. Min Stack
//
//  Created by 冯嘉晨 on 2019/2/19.
//  Copyright © 2019 冯嘉晨. All rights reserved.
//
//Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
//push(x) -- Push element x onto stack.
//pop() -- Removes the element on top of the stack.
//top() -- Get the top element.
//getMin() -- Retrieve the minimum element in the stack.
//Example:
//MinStack minStack = new MinStack();
//minStack.push(-2);
//minStack.push(0);
//minStack.push(-3);
//minStack.getMin();   --> Returns -3.
//minStack.pop();
//minStack.top();      --> Returns 0.
//minStack.getMin();   --> Returns -2.
#include <iostream>
#include <stack>
using namespace std;
class MinStack {
private:
    stack<int> s;
    stack<int> mins;
public:
    /** initialize your data structure here. */

    MinStack() {
        
    }
    
    void push(int x) {
        s.push(x);
        if(mins.empty()||(!mins.empty()&&mins.top()>=x)){
            mins.push(x);
        }
    }
    
    void pop() {
        if(!s.empty()){
            if(s.top()==mins.top()){
                mins.pop();
            }
            s.pop();
        }
    }
    
    int top() {
        if(!s.empty())
            return s.top();
        return 0;
    }
    
    int getMin() {
        if(!mins.empty())
            return mins.top();
        return 0;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
