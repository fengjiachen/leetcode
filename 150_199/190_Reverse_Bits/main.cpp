//
//  main.cpp
//  190. Reverse Bits
//
//  Created by 冯嘉晨 on 2019/3/13.
//  Copyright © 2019 冯嘉晨. All rights reserved.
//
//Reverse bits of a given 32 bits unsigned integer.
#include <iostream>
using namespace std;
//uint32_t reverseBits(uint32_t n) {
//    uint32_t mask = 1;
//    uint32_t ans = 0;
//    for(int i=0;i<32;i++){
//        ans = (ans<<1)|((n&mask)>>i);
//        mask = mask<<1;
//    }
//    return ans;
//}
uint32_t reverseBits(uint32_t n) {
    uint32_t ans = 0;
    for(int i=0;i<32;i++){
        ans = (ans<<1)|((n>>i)&1);
    }
    return ans;
}
int main(int argc, const char * argv[]) {
    // insert code here...43261596 vs 964176192
    std::cout << "Hello, World!\n";
    unsigned long long t = 43261596 ;
    cout<<reverseBits(t)<<endl;
    return 0;
}
