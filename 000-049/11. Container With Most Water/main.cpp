//
//  main.cpp
//  11. Container With Most Water
//
//  Created by 冯嘉晨 on 2018/12/25.
//  Copyright © 2018 冯嘉晨. All rights reserved.
//
//11. Container With Most Water
//Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.
//
//Note: You may not slant the container and n is at least 2.

#include <iostream>
#include <vector>
using namespace std;
int maxArea(vector<int>& height) {
    int len = (int)height.size();
    int sum = 0;
    for(int i=0;i<len;i++){
        for(int j=i+1;j<len;j++){
            int tem = min(height[i],height[j])*(j-i);
            if(tem>sum)
                sum = tem;
        }
    }
    return sum;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    int n[] = {1,1,6,2,5,4,8,3,7};
    vector<int> h(n,n+2);
    cout<<maxArea(h)<<endl;
    return 0;
}
