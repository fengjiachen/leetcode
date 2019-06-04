//
//  main.cpp
//  20. Valid Parentheses
//
//  Created by 冯嘉晨 on 2018/12/18.
//  Copyright © 2018 冯嘉晨. All rights reserved.
//
//20. Valid Parentheses
//Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//
//An input string is valid if:
//
//Open brackets must be closed by the same type of brackets.
//Open brackets must be closed in the correct order.
//Note that an empty string is also considered valid.
//
//Example 1:
//
//Input: "()"
//Output: true
//Example 2:
//
//Input: "()[]{}"
//Output: true
//Example 3:
//
//Input: "(]"
//Output: false
//Example 4:
//
//Input: "([)]"
//Output: false
//Example 5:
//
//Input: "{[]}"
//Output: true

#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s) {
    stack<char> st;
    int n = (int)s.length();
    for(int i =0;i<n;i++){
        if(s[i]=='[' || s[i]=='{' || s[i]=='('){
            st.push(s[i]);
        }else if(s[i]==']'){
            if(st.size()==0)
                return false;
            char c = st.top();
            if(c=='['){
                st.pop();
            }else{
                return false;
            }
        }else if(s[i]=='}'){
            if(st.size()==0)
                return false;
            char c = st.top();
            if(c=='{'){
                st.pop();
            }else{
                return false;
            }
        }else if(s[i]==')'){
            if(st.size()==0)
                return false;
            char c = st.top();
            if(c=='('){
               st.pop();
            }else{
                return false;
            }
        }
    }
    if(st.size()==0){
        return true;
    }else{
        return false;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    string s("}");
    cout<<isValid(s)<<endl;
    return 0;
}
