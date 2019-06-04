//
//  main.cpp
//  204. Count Primes
//
//  Created by 冯嘉晨 on 2019/3/17.
//  Copyright © 2019 冯嘉晨. All rights reserved.
//
//Count the number of prime numbers less than a non-negative number, n.
//
//Example:
//
//Input: 10
//Output: 4
//Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
#include <iostream>
#include <cmath>
using namespace std;
int countPrimes(int n) {
    if(n==0)
        return 0;
    bool isPrimes[n];
    for(int i=0;i<n;i++){
        isPrimes[i] = true;
    }
    int lastNotPrime = sqrt(n);
    for(int i=2;i<=lastNotPrime;i++){
        if(isPrimes[i]==true){
            for(unsigned times=2;times*i<n;times++){
                isPrimes[i*times]=false;
            }
        }
    }
    int count = 0;
    for(int i=2;i<n;i++){
        if(isPrimes[i]==true){
            count++;
        }
    }
    return count;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    cout<<countPrimes(100)<<endl;
    return 0;
}
