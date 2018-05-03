/*
想用快速选择的方法来实现，但是发现牛客网并不能在规定时间跑完。。但是在mac秒完成。。
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    void selectK(vector<int> &input,int k,int l,int r){
        if(k==0 || l>r ) return;
        int i=0;
        for(int j=l;j<r;j++){
            if(input[j]<=input[r]) {
                swap(input[i+l],input[j]);
                i++;
            }
        }
        if(i == r-l) i--;
        else {swap(input[i+l],input[r]);i++;}
        // cout<<"input[r] "<<input[r]<<endl; 
        // cout<<"i "<<i<<endl;
        // cout<<"l is: "<<l<<"r is "<<r<<endl;
        // for(int k=0;k<i;k++) cout<<input[l+k];
        // cout<<endl;
        if(k == i) return ;
        if(i<k){
            selectK(input,k-i,l+i,r);
        }
        else if(i>k){
            selectK(input,k,l,l+i);
        }
    }
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if(input.empty()) return input;
        selectK(input,k,0,input.size()-1);
        vector<int> ret(input.begin(),input.begin()+k);
        //input.erase(input.begin()+k,input.end());
        return ret;
    }
    
};

int main(int argc, char const *argv[])
{
	vector<int> v;
	v.push_back(4);
	v.push_back(5);
	v.push_back(1);
	v.push_back(6);
	v.push_back(2);
	v.push_back(7);
	v.push_back(3);
	v.push_back(8);

	Solution s;
	vector<int> ret;
	ret = s.GetLeastNumbers_Solution(v,4);
	for (int i = 0; i < ret.size(); ++i)
	{
		cout<<ret[i]<<endl;
	}
	return 0;
}