/*
统计一个数字在排序数字中出现的次数
通过寻找目标数字的第一个出现的位置，然后寻找目标数字+1的出现的第一个位置，然后相减，得到结果。
*/

//version 1(4 ms)
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        if(data.empty()) return 0;
        int next = binarySearch(data,k+1);
        int cur = binarySearch(data,k);
        if(data[cur] == k) return next - cur;
        return 0;
    }
    int binarySearch(vector<int> &data,int target){
        int l = 0, r = data.size()-1, mid;
        while(l<=r){
            mid = l + (r-l)/2;
            if(data[mid] == target){
                if(l == mid) return l;
                else r = mid;
            }
            else if(data[mid] < target) l = mid + 1;
            else r = mid - 1;
        }
        return l;
    }
};