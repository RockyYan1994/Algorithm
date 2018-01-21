/*
    first
    首先想到和4Sum类似的方法，采用map来存储vector数组，然后用两个for循环来遍历每两个数，得出和，取反然后在map中查找，
    这个方法由于输出和4Sum不同，导致会出现重复的现象，要去除重复现象需要增加大量计算。
    
    在查看discussion之后，使用固定头，后面两个指针往中间收缩的方法，通过每次更新三个指针都确保不同值的情况下，确保了没有重复的情况。
    考虑到第一个数必须小于或者等于0，因此外层循环的时候可以将判定条件设置为第一个数<=0。

    第四版本：在添加vector的时候，通过使用三次push_back太过于耗时间，通过直接添加 {nums[head],nums[rear],nums[i]}的方法一次性添加，
    减少了大量的时间。
*/


#include <iostream>
#include <map>
#include <vector>
#include <stdio.h>

using namespace std;

vector<vector<int> > threeSum(vector<int>& nums);

int main(int argc, char const *argv[])
{
    vector<int> input;

    input.push_back(-1);
    input.push_back(0);
    input.push_back(1);
    input.push_back(2);
    input.push_back(-1);
    input.push_back(-4);

    vector<vector<int> > output;
    output = threeSum(input);

    for(int i=0;i<output.size();i++){
        for (int j = 0; j < output[i].size(); ++j){
            cout<<'\t'<<output[i][j];
        }
        cout<<endl;
    }
    cout<<"end flag"<<endl;
    return 0;
}


vector<vector<int> > threeSum(vector<int>& nums) {
    map<int,vector<int> > mat;
    vector<vector<int> > ret;
    for(int i=0;i<nums.size();i++){
        mat[nums[i]].push_back(i);
    }

    for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums.size();j++){
            int cur_sum = nums[i]+nums[j];
            cout<<"cur sum is "<<cur_sum<<endl;
            map<int,vector<int> >::iterator it;
            it = mat.find(-cur_sum);
            if(it!=mat.end()){
                for(int k=0;k<(it->second).size();k++){
                    if((it->second)[k]!=i&&(it->second)[k]!=j){
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[(it->second)[k]]);
                        ret.push_back(temp);
                    }
                }
            }
        }
    }
    return ret;
}

// version 2
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         vector<vector<int> > ret;
//         int rep = 0;
//         for(int i=0;i<nums.size();i++){
//             if(nums[i]>0) break;
//             if(nums[i]==rep) continue;
//             for(int j=i+1;j<nums.size();j++){
//                 rep = nums[j];
//                 for(int k=nums.size()-1;k>j;k--){
//                     if(nums[i]+nums[j]+nums[k]<0) break;
//                     if(nums[i]+nums[j]+nums[k]==0) {
//                         vector<int> temp;
//                         temp.push_back(nums[i]);
//                         temp.push_back(nums[j]);
//                         temp.push_back(nums[k]);
//                         ret.push_back(temp);
//                     }
//                 }
//             }
//         }
//         return ret;
//     }
// };

//versio 3 (136 ms)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > ret;
        if(nums.size()<3) return ret;
        sort(nums.begin(),nums.end());
        int i=0;
        while(nums[i]<=0){
            int head = i+1;
            int rear = nums.size()-1;
            
            while(head<rear){
                if(nums[head]+nums[rear]==-nums[i]){
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[head]);
                    temp.push_back(nums[rear]);
                    ret.push_back(temp);
                }
                
                if(nums[head]+nums[rear]>-nums[i]){
                    while(nums[rear]==nums[rear-1]) rear--;
                    rear--;
                }
                else{
                    while(nums[head]==nums[head+1]) head++;
                    head++;
                }
            }
            while(nums[i]==nums[i+1]) i++;
            i++;
            
        }
        
        return ret;
    }
};

//version 4(104 ms)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > ret;
        if(nums.size()<3) return ret;
        sort(nums.begin(),nums.end());
        int i=0;
        while(nums[i]<=0){
            int head = i+1;
            int rear = nums.size()-1;
            
            while(head<rear){
                int sum = nums[head]+nums[rear]+nums[i];
                if(sum==0){
                    ret.push_back({nums[head],nums[rear],nums[i]});
                }
                
                if(sum>0){
                    while(nums[rear]==nums[rear-1]) rear--;
                    rear--;
                }
                else{
                    while(nums[head]==nums[head+1]) head++;
                    head++;
                }
            }
            while(nums[i]==nums[i+1]) i++;
            i++;
            
        }
        
        return ret;
    }
};