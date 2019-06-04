//
//  main.cpp
//  56. Merge Intervals
//
//  Created by 冯嘉晨 on 2019/4/10.
//  Copyright © 2019 冯嘉晨. All rights reserved.
//
//Given a collection of intervals, merge all overlapping intervals.
//
//Example 1:
//
//Input: [[1,3],[2,6],[8,10],[15,18]]
//Output: [[1,6],[8,10],[15,18]]
//Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
//Example 2:
//
//Input: [[1,4],[4,5]]
//Output: [[1,5]]
//Explanation: Intervals [1,4] and [4,5] are considered overlapping.
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

//Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
bool compare(const Interval &a, const Interval &b){
    return a.start<b.start;
}
vector<Interval> merge(vector<Interval>& intervals) {
    vector<Interval>ans;
    int l = (int)intervals.size();
    if(l==0){
        return ans;
    }else if(l==1){
        return intervals;
    }
    sort(intervals.begin(), intervals.end(), compare);
    int start = intervals[0].start;
    int end = intervals[0].end;
    for(int i=1;i<l;i++){
        
        if(intervals[i].start>end ){
            ans.push_back(Interval(start,end));
            start = intervals[i].start;
            end = intervals[i].end;
        }else{
            start = min(start,intervals[i].start);
            end = max(end,intervals[i].end);
        }
    }
    ans.push_back(Interval(start,end));
    return ans;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<Interval> i;
    i.push_back(Interval(1,3));
    i.push_back(Interval(0,0));
    i.push_back(Interval(-1,10));
    i.push_back(Interval(15,18));
    vector<Interval> a;
    a = merge(i);
    for(int j=0;j<(int)a.size();j++){
        cout<<a[j].start<<"\t"<<a[j].end<<endl;
    }
    return 0;
}
