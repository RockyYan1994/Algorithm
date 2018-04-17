/*
    first
    一开始想直接分情况讨论，但是由于情况太多，很难直接实现，查看discussion之后发现关键啊在于sort，根据intervals。start来判断。
    但是实现之后发现时间超时。。
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.empty()) return intervals;
        vector<Interval> res;
        res.push_back(intervals[0]);
        sort(intervals.begin(),intervals.end(),[](Interval a,Interval b){return a.start<=b.start;});
        for(int i=0;i<intervals.size();i++){
            int back = res.size()-1;
            if(intervals[i].start>res[back].end){
                res.push_back(intervals[i]);
            }   
            else{
                res[back].end = max(intervals[i].end,res[back].end);
            }
        }
        return res;
    }
};