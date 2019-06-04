//
//  main.cpp
//  60. Permutation Sequence
//
//  Created by 冯嘉晨 on 2019/4/10.
//  Copyright © 2019 冯嘉晨. All rights reserved.
//
//The set [1,2,3,...,n] contains a total of n! unique permutations.
//
//By listing and labeling all of the permutations in order, we get the following sequence for n = 3:
//
//"123"
//"132"
//"213"
//"231"
//"312"
//"321"
//Given n and k, return the kth permutation sequence.
//
//Note:
//
//Given n will be between 1 and 9 inclusive.
//Given k will be between 1 and n! inclusive.
//Example 1:
//
//Input: n = 3, k = 3
//Output: "213"
//Example 2:
//
//Input: n = 4, k = 9
//Output: "2314"
#include <iostream>
#include <vector>
using namespace std;
int jiechen(int n){
    if(n==0||n==1){
        return 1;
    }else{
        return n*jiechen(n-1);
    }
}
string getPermutation(int n, int k) {
    if(n==0){
        return "";
    }
    vector<int>p;
    for(int i=1;i<=n;i++){
        p.push_back(i);
    }
    string ans = "";
    while (n>1) {
        int jc = jiechen(n-1);
        int lable = (k+jc-1)/jc;
//        cout<<"n="<<n<<" jc="<<jc<<" lable="<<lable<<endl;
        ans += '0'+p[lable-1];
        p.erase(p.begin()+lable-1);
        k -= (lable-1)*jc;
        n--;
    }
    for(int i=0;i<(int)p.size();i++){
        ans += '0'+p[i];
    }
    
    return ans;
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    cout<<getPermutation(4, 24)<<endl;
    return 0;
}
