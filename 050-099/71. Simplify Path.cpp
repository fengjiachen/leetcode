//
//  main.cpp
//  71. Simplify Path
//
//  Created by 冯嘉晨 on 2019/5/28.
//  Copyright © 2019 冯嘉晨. All rights reserved.
//
//Given an absolute path for a file (Unix-style), simplify it. Or in other words, convert it to the canonical path.
//
//In a UNIX-style file system, a period . refers to the current directory. Furthermore, a double period .. moves the directory up a level. For more information, see: Absolute path vs relative path in Linux/Unix
//
//Note that the returned canonical path must always begin with a slash /, and there must be only a single slash / between two directory names. The last directory name (if it exists) must not end with a trailing /. Also, the canonical path must be the shortest string representing the absolute path.
//Example 1:
//
//Input: "/home/"
//Output: "/home"
//Explanation: Note that there is no trailing slash after the last directory name.
//Example 2:
//
//Input: "/../"
//Output: "/"
//Explanation: Going one level up from the root directory is a no-op, as the root level is the highest level you can go.
//Example 3:
//
//Input: "/home//foo/"
//Output: "/home/foo"
//Explanation: In the canonical path, multiple consecutive slashes are replaced by a single one.
//Example 4:
//
//Input: "/a/./b/../../c/"
//Output: "/c"
//Example 5:
//
//Input: "/a/../../b/../c//.//"
//Output: "/c"
//Example 6:
//
//Input: "/a//b////c/d//././/.."
//Output: "/a/b/c"
#include <iostream>
#include <stack>
using namespace std;
string simplifyPath(string path) {
    stack<string> s;
    int len = (int)path.length();
    for(int i=0;i<len;i++){
        while (i<len&&'/'==path[i]) {
            i++;
        }
        string temp = "";
        while (i<len&&path[i]!='/') {
            temp += path[i++];
        }
        if(".."==temp&&!s.empty()){
            s.pop();
        }else if(temp!="."&&temp!=""&&temp!=".."){
            s.push(temp);
        }
    }
    
    if(s.empty())
        return "/";
    string r = "";
    while (!s.empty()) {
        r = "/"+s.top()+r;
        s.pop();
    }
    return r;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    string path = "/home//foo/";
    cout<<simplifyPath(path)<<endl;
    return 0;
}
