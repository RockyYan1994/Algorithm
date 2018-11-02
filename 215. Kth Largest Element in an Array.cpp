/*
	方法一：通过排序之后直接取。
	方法二：priority_queue实现。
	方法三：快速选择。
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<int, vector<int>, std::less<int>> pq(nums.begin(), nums.end());
        for(int i=1;i<k;i++) {
            pq.pop();
        }
        return pq.top();
    }
};