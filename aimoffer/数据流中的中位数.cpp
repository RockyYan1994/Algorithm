/*
如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
这道题主要采用的就是通过两个队列来实现，一个队列采用greater，一个采用less，根据每次插入调整，使两个队列保持l==g或者l==g+1。
*/

//version 1(4 ms)
class Solution {
public:
	// the second parameter is container, default is vector<T>,but I don't know why we can't omit it.
    priority_queue<int,vector<int>,greater<int> > g;
    priority_queue<int,vector<int>,less<int> > l; // less is the default, so we can just use priority_queue<int> 
    void Insert(int num)
    {
        if(l.empty() || num < l.top()) l.push(num);
        else g.push(num);
        if(l.size() == g.size()+2) { g.push(l.top()); l.pop(); }
        if(l.size()+1 == g.size()) { l.push(g.top()); g.pop(); }
    }

    double GetMedian()
    { 
        return (l.size()==g.size())?(l.top()+g.top())/2.0:l.top();
    }

};