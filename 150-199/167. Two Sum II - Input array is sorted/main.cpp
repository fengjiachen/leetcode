//
//  main.cpp
//  167. Two Sum II - Input array is sorted
//
//  Created by 冯嘉晨 on 2019/3/7.
//  Copyright © 2019 冯嘉晨. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
vector<int> twoSum(vector<int>& numbers, int target) {
    int l = 0, r = (int)numbers.size()-1;
    long long t = (long)target;
    long long temp;
    while (l<r) {
        temp = numbers[l]+numbers[r];
        if(temp<t){
            l++;
        }else if(temp>t){
            r--;
        }else{
            break;
        }
    }
    return vector<int>{l+1,r+1};
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a{2,7,11,15};
    vector<int> b = twoSum(a, 9);
    for(int i=0;i<(int)b.size();i++){
        cout<<b[i]<<endl;
    }
    
    return 0;
}
