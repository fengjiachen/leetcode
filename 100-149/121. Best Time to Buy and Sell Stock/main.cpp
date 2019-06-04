//
//  main.cpp
//  121. Best Time to Buy and Sell Stock
//
//  Created by 冯嘉晨 on 2019/2/15.
//  Copyright © 2019 冯嘉晨. All rights reserved.
//
//121. Best Time to Buy and Sell Stock
//Say you have an array for which the ith element is the price of a given stock on day i.
//
//If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.
//
//Note that you cannot sell a stock before you buy one.
//
//Example 1:
//
//Input: [7,1,5,3,6,4]
//Output: 5
//Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
//Not 7-1 = 6, as selling price needs to be larger than buying price.
//Example 2:
//
//Input: [7,6,4,3,1]
//Output: 0
//Explanation: In this case, no transaction is done, i.e. max profit = 0.
#include <iostream>
#include <vector>
using namespace std;
int maxProfit(vector<int>& prices) {
    int profit = 0;
    int len = (int)prices.size();
    if(len==0)
        return profit;
    int in = prices[0];
    for(int i=1;i<len;i++){
        if(profit<(prices[i]-in))
            profit = prices[i]-in;
        if(prices[i]<in)
            in = prices[i];
    }
    return profit;
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<int> pirces={7};
    cout<<maxProfit(pirces)<<endl;
    return 0;
}
