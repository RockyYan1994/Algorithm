/*

*/

//version 1(36 ms)
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int cnt = 0;
        int n = nums.size();
        if (n < 3) return 0;        
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                for (int k=j+1; k<n; k++) {
                    if (nums[i] + nums[j] + nums[k] < target) {
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};


//version 2(4 ms)
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int cnt = 0;
        if (nums.size() < 3) return 0;
        sort(nums.begin(), nums.end());
        for (int i=0; i<nums.size()-2; i++) {
            int l = i+1, r = nums.size()-1;
            while (l < r) {
                if (nums[i] + nums[l] + nums[r] < target) {
                    cnt += r - l;
                    l++;
                } else {
                    r--;
                }
            }
        }
        return cnt;
    }
};