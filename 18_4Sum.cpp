/*
	first
	首先想到使用head、back、inner_head、inner_back来进行两层的遍历，但是并不能完全遍历整个数组，因为外层的head和back往中间收缩，
	导致头尾会有不能遍历到的地方。最后采用的是和3Sum类似的方法，不过外层变成了两层的循环。

	优化：在通过在循环中添加两个判断条件：该次循环最小的四个之和都大于的情况，则退出循环；该次循环中最大组合之和都小于的情况，进入下次循环。
*/
//version 1(52 ms)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > res;
        if(nums.size()<4) return res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-3;i++){
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;
            for(int j = i+1;j<nums.size()-2;j++){
                int inner_head = j+1;
                int inner_back = nums.size()-1;
                while(inner_head<inner_back){
                    int sum = nums[i]+nums[j]+nums[inner_head]+nums[inner_back];
                    if(sum == target){
                        res.push_back({nums[i],nums[j],nums[inner_head],nums[inner_back]});
                    }

                    if(sum > target){
                        while(nums[inner_back]==nums[inner_back-1]) inner_back--;
                        inner_back--;
                    }
                    else{
                        while(nums[inner_head]==nums[inner_head+1]) inner_head++;
                        inner_head++;
                    }
                }
                while(nums[j]==nums[j+1]) j++;
            }
            while(nums[i]==nums[i+1]) i++;
        }
        return res;
    }
};

//version 2(14 ms)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > res;
        if(nums.size()<4) return res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-3;i++){
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;
            if(nums[i]+nums[nums.size()-3]+nums[nums.size()-2]+nums[nums.size()-1]<target) continue;
            for(int j = i+1;j<nums.size()-2;j++){
                if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) break;
                if(nums[i]+nums[j]+nums[nums.size()-2]+nums[nums.size()-1]<target) continue;
                int inner_head = j+1;
                int inner_back = nums.size()-1;
                while(inner_head<inner_back){
                    int sum = nums[i]+nums[j]+nums[inner_head]+nums[inner_back];
                    if(sum == target){
                        res.push_back({nums[i],nums[j],nums[inner_head],nums[inner_back]});
                    }

                    if(sum > target){
                        while(nums[inner_back]==nums[inner_back-1]) inner_back--;
                        inner_back--;
                    }
                    else{
                        while(nums[inner_head]==nums[inner_head+1]) inner_head++;
                        inner_head++;
                    }
                }
                while(nums[j]==nums[j+1]) j++;
            }
            while(nums[i]==nums[i+1]) i++;
        }
        return res;
    }
};