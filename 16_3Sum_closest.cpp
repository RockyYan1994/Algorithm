/*
    first
    首先想到使用和3sum同样的策略，固定一个数，另外两个往中间收敛，在实现过程中，通过优化sum只计算一次和通过添加一个判断条件让（
    最小的三个数相加然后减去target，如果结果比min_dis还要大，就直接退出循环，因为后面的所有结果都比当前还要大。）
*/

//version 1(22 ms)
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size()<3) return 0;
        sort(nums.begin(),nums.end());
        int ret = 0;
        int min_dis = INT_MAX;
        for(int i=0;i<nums.size();i++){
            int head = i+1;
            int back = nums.size()-1;
            
            while(head<back){
                int sum = nums[head]+nums[back]+nums[i];
                int cur_dis = sum>target?sum-target:target-sum;
                if(cur_dis<min_dis){
                    ret = sum;
                }
                if(sum>target){
                    back--;
                }
                else{
                    head++;
                }
                min_dis = min(cur_dis,min_dis);
            }
        }
        return ret;
    }
};

//version 2(16 ms)
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size()<3) return 0;
        sort(nums.begin(),nums.end());
        int ret = 0;
        int min_dis = INT_MAX;
        for(int i=0;i<nums.size();i++){
            int head = i+1;
            int back = nums.size()-1;
            
            while(head<back){
                int sum = nums[head]+nums[back]+nums[i];
                int cur_dis = abs(sum-target);
                if(cur_dis<min_dis){
                    min_dis = cur_dis;
                    ret = sum;
                }
                if(sum>target){
                    back--;
                }
                else{
                    head++;
                }
            }
        }
        return ret;
    }
};


//version 3(16 ms)
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size()<3) return 0;
        sort(nums.begin(),nums.end());
        int ret = nums[0]+nums[1]+nums[2];
        for(int i=0;i<nums.size();i++){
            int head = i+1;
            int back = nums.size()-1;
            
            while(head<back){
                int sum = nums[head]+nums[back]+nums[i];
                if(abs(sum-target)<abs(ret-target)){
                    ret = sum;
                }
                if(sum>target) back--;
                else head++;
            }
        }
        return ret;
    }
};

//version 4(10 ms)
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size()<3) return 0;
        sort(nums.begin(),nums.end());
        int ret = 0;
        int min_dis = INT_MAX;
        for(int i=0;i<nums.size()-2;i++){
            int head = i+1;
            int back = nums.size()-1;
            if(nums[i]+nums[i+1]+nums[i+2]-target>min_dis) break;
            while(head<back){
                int sum = nums[head]+nums[back]+nums[i];
                int cur_dis = abs(sum-target);
                
                if(cur_dis<min_dis){
                    min_dis = cur_dis;
                    ret = sum;
                }
                if(sum>target){
                    back--;
                }
                else{
                    head++;
                }
            }
        }
        return ret;
    }
};