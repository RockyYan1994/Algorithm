/*

*/

//version 1(100 ms)
class MedianFinder {
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    int size;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        size = 0;
    }
    
    void addNum(int num) {        
        size++;
        min_heap.push(num);
        int i = min_heap.size(), j = max_heap.size();
        if (i > j+1 || j!=0 && min_heap.top() < max_heap.top()) {
            int temp = min_heap.top();
            min_heap.pop();
            max_heap.push(temp);
        }
        i = min_heap.size(), j = max_heap.size();
        if (i < j) {
            int temp = max_heap.top();
            max_heap.pop();
            min_heap.push(temp);
        }
    }
    
    double findMedian() {
        if (size<2) return min_heap.top();
        if (size%2 == 0) {
            return ((double)max_heap.top() + (double)min_heap.top()) / 2; 
        } else {
            return min_heap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */