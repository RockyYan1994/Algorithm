/*
	first
	考虑到这是一个二分查找问题，关键在于不能在找到mid的第一时间退出，而且时间复杂度必须为O（logn）。因此想采用在当mid==target的时候进行判断，将
	head和back同时考虑进来，然后找出最小的start和最大的end。
	第二个方法想到使用递归实现，并且不停查找，左右两边同时进行，直到head>back。
	看了discussion之后发现可以通过通过二分查找找到开头，然后通过二分查找找到结尾的方法。（from stellari）
*/

//version 1(12 ms)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = -1, end = -1;
        int head = 0, back = nums.size()-1;
        while(head<=back){
            int mid = head + (back-head)/2;
            if(nums[mid]==target){
                start = (start>mid||start==-1)?mid:start;
                end = (end<mid||end==-1)?mid:end;
                if(nums[head]==target) {
                    start = (start>head||start==-1)?head:start;
                    end = (end<head||end==-1)?head:end;
                    head = mid + 1;
                }
                else ++head;
                if(nums[back]==target) {
                    start = (start>back||start==-1)?back:start;
                    end = (end<back||end==-1)?back:end;
                    back = mid - 1;
                }
                else --back;
            }
            else if(nums[mid]<target) head = mid + 1;
            else back = mid - 1;
        }
        return {start,end};
    }
};

//version.2(16 ms)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2,-1);
        search(nums,0,nums.size()-1,target,res);
        return res;
    }
    void search(vector<int>& nums,int head,int back,int target,vector<int> &res){
        if(head>back) return;
        int mid = head + (back - head)/2;
        if(nums[mid]==target){
            res[0] = (mid<res[0]||res[0]==-1)?mid:res[0];
            res[1] = (mid>res[1]||res[1]==-1)?mid:res[1];
            search(nums,head,mid-1,target,res);
            search(nums,mid+1,back,target,res);
        }
        else if(nums[mid]>target) search(nums,head,mid-1,target,res);
        else search(nums,mid+1,back,target,res);
    }
};

//version of stellari 
vector<int> searchRange(int A[], int n, int target) {
    int i = 0, j = n - 1;
    vector<int> ret(2, -1);
    // Search for the left one
    while (i < j)
    {
        int mid = (i + j) /2;
        if (A[mid] < target) i = mid + 1;
        else j = mid;
    }
    if (A[i]!=target) return ret;
    else ret[0] = i;
    
    // Search for the right one
    j = n-1;  // We don't have to set i to 0 the second time.
    while (i < j)
    {
        int mid = (i + j) /2 + 1;	// Make mid biased to the right
        if (A[mid] > target) j = mid - 1;  
        else i = mid;				// So that this won't make the search range stuck.
    }
    ret[1] = j;
    return ret; 
}