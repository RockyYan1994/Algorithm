/*

*/

//version 1(20 ms)
class MovingAverage {
    queue<int> nums;
    int size;
    int sum;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        this->size = size;        
        this->sum = 0;
    }
    
    double next(int val) {
        if (nums.size() == size) {
            sum -= nums.front();
            nums.pop();
            nums.push(val);
            sum += val;
        } else {
            sum += val;
            nums.push(val);
        }
        return (double)sum / nums.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */