/*
*	这个方法主要是根据不断向前，当遇到当前i的高度比栈顶大的时候，入栈；如果比其小，那么就弹出，并且计算之前顶的面积，最后在栈为空或者比栈顶大的时候，
*	将这个元素入栈。这个在最后的时候加入一个值（高）为0的点。还有一个点就是在计算宽度的时候，因为没有包含当前i，而是计算i-1到栈中第二个元素的索引，
*	同时还要考虑如果栈中只有一个元素的情况，这样就需要先pop一次，然后取出栈顶索引nextTop = index.empty()? -1: index.top(); 然后再用nextTop来
*	进行计算。
*
*
*/

//version 1(12 ms)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> index;
        heights.push_back(0);
        int maxVal = 0;
        for(int i=0;i<heights.size();i++){
            while(!index.empty() && heights[index.top()] > heights[i] ){
                int h = heights[index.top()];
                index.pop();
                int nextTop = index.empty()? -1  : index.top();
                maxVal = max(maxVal, h*(i-1-nextTop));
            }
            index.push(i);
        }
        return maxVal;
    }
};