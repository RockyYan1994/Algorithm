//first
/*
    DP问题，在考虑的时候考虑到最后一个，通过从倒数第二个遍历距离，找到第一个能够到达的点，将这个点设置为最后一个点，重复直到到达第一个点，若中途某个点没找到，则退出。
*/

#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

bool canJump(vector<int>& nums);

int main(){
    vector<int> v;
    for(int i=7;i>0;i--){
        v.push_back(i);
    }
    bool sign = canJump(v);
    return 0;
}



// bool canJump(vector<int>& nums) {
//     int pos = 0;
//     if(nums.size()<2) return true;
//     for(int i=nums.size()-2;i>=0;i--){
//         if(nums[i]>=(nums.size()-1)-i){
//             pos = i;
//             cout<<"pos = "<<pos<<endl;
//             nums.erase(nums.begin()+pos+1,nums.end());
//             return canJump(nums);
//         }
//     }
//     return false;
// }

 bool canJump(vector<int>& nums) {
    int pos = 0;
    
    bool sign = true;
    while(true){
        if(nums.size()<2) break;
        if(sign==false) break;
        int next = 0;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]>=(nums.size()-1)-i){
                pos = i;
                nums.erase(nums.begin()+pos+1,nums.end());
                next=1;
                break;
            }
        }
        if(next==0)
            sign = false;
    }
    
    return sign;
    }