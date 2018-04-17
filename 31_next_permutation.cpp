/*
	first
	一开始没看懂permutation，后来发现是一种寻找组合的方法。根据输入，找到下一个permutation状态，如果在最末尾则返回开头。
	具体实现采用discussion上的方法。如下：
	(from  jianchao.li.fighter)
	Find the largest index k such that nums[k] < nums[k + 1]. If no such index exists, the permutation is sorted in descending order, just reverse it to ascending order and we are done. For example, the next permutation of [3, 2, 1] is [1, 2, 3].
	Find the largest index l greater than k such that nums[k] < nums[l].
	Swap the value of nums[k] with that of nums[l].
	Reverse the sequence from nums[k + 1] up to and including the final element nums[nums.size() - 1].

	查看了最快速的答案发现reverse后面的操作也可以换成sort后面的序列，但是感觉原因不在于此，可能是在于使用了自己实现的reverse。
	有一个直接实现的函数。。next_permutation(begin(nums), end(nums));
*/

//version 1(15 ms)
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        bool des = true;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]<nums[i+1]){
                des = false;
                break;
            }
        }
        if(des){
            reverse(nums.begin(),nums.end());
            return ;
        }
        for(int i=nums.size()-1;i>0;i--){
            if(nums[i-1]<nums[i]) { 
                int j;
                for(j=nums.size()-1;j>i-1;j--){
                    if(nums[i-1]<nums[j]) break;
                }
                swap(nums[i-1],nums[j]);
                if(i!=nums.size()-1){
                    reverse(nums.begin()+i,nums.end());
                }
                break;
            }
        }
    }
};





//version other's(12 ms)
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int sz = nums.size();
        if( sz <=1 ) return;
        for(int i=sz-1; i>0; --i){
            //printf(" %d %d\n", nums[i], nums[i-1]);
            if( nums[i] > nums[i-1] ){
                for( int j=sz-1; j > i-1; j--){
                    //printf("---- %d %d\n", nums[i-1], nums[j]);
                    if( nums[i-1] < nums[j]) {
                        swap( nums[i-1], nums[j]);
                        break;
                    }
                }
                sort(nums.begin()+i, nums.end());
                return;
            }
        }
        
        for(int i=0; i<sz/2; ++i) {
            swap(nums[i], nums[sz-1-i]);
        }
    }
};

//version of StefanPochmann's(15 ms)
void nextPermutation(vector<int>& nums) {
    int i = nums.size() - 1, k = i;
    while (i > 0 && nums[i-1] >= nums[i])
        i--;
    for (int j=i; j<k; j++, k--)
        swap(nums[j], nums[k]);
    if (i > 0) {
        k = i--;
        while (nums[k] <= nums[i])
            k++;
        swap(nums[i], nums[k]);
    }
}