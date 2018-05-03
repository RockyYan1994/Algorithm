/*
给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。
例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}；
查看了discussion之后，发现这个题主要可以采用一个deque来实现，dq中存的是索引（坐标），当遍历一个值的时候，将dq中比他对应值小的都pop，并且位置dq中front
是有效值，这样确保deque中的front是指向当前窗口的合法最大值。
*/

//version 1(3 ms)
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> ret;
        deque<int> dq;
        for(int i=0;i<num.size();i++){
            while(dq.size() && num[dq.back()] <= num[i]) dq.pop_back();
            while(dq.size() && i-dq.front() >= size) dq.pop_front();
            dq.push_back(i);
            if(size>0 && i+1>=size) ret.push_back(num[dq.front()]);
        }
        return ret;
    }
};