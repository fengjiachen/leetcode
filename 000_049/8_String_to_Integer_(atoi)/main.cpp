//
//  main.cpp
//  8. String to Integer (atoi)
//
//  Created by 冯嘉晨 on 2018/12/24.
//  Copyright © 2018 冯嘉晨. All rights reserved.
//
//8. String to Integer (atoi)
//Implement atoi which converts a string to an integer.
//
//The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.
//
//The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.
//
//If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.
//
//If no valid conversion could be performed, a zero value is returned.
//
//Note:
//
//Only the space character ' ' is considered as whitespace character.
//Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. If the numerical value is out of the range of representable values, INT_MAX (231 − 1) or INT_MIN (−231) is returned.

#include <iostream>
using namespace std;
int myAtoi(string str) {
    int len = (int)str.length();
    int i=0,sum=0,flag=1,psum=0;
    while(str[i]==' '){
        i++;
    }
    if(str[i]=='-'){
        flag *= -1;
        i++;
    }else if(str[i]=='+'){
        i++;
    }else if (str[i]>'9' || str[i]<'0'){
        return sum;
    }

    for(;i<len;i++){
        if(str[i]>'9' || str[i]<'0'){
            return flag*sum;
        }else{
            psum = sum;
            sum = sum*10 + (str[i]-'0');
            cout<<"i="<<i<<" psum="<<psum<<" sum="<<sum<<endl;
            cout<<"c1="<<(((sum-(str[i]-'0'))/10)!=psum)<<endl;
            cout<<"c2="<<(sum<psum)<<endl;
            if(((sum-(str[i]-'0'))/10)!=psum||sum<psum){
                if(flag>0)
                    return INT_MAX;
                else
                    return INT_MIN;
            }
        }
    }
    return flag*sum;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    string s("2147483648");
    cout<<myAtoi(s)<<endl;
    return 0;
}
