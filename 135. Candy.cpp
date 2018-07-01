/*
	查看了discussion第一个答案，思路是：
	1，首先用一个长度和ratings相同的vector，初始化所有元素为1来表示至少每个有一个糖果。
	2，正向遍历一次，如果当前的rating高于上一个，则当前的rating等于上一个rating+1.
	3，反向遍历一次，如果当前的rating高于后一个，则当前的rating等于max(candy[i-1],candy[i]+1)
	这样操作之后vector的sum就是结果。
*/

//version 1(27 ms)
class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.size()<=1) return ratings.size();
        vector<int> candy(ratings.size(), 1);
        for(int i=1;i<ratings.size();i++){
            if( ratings[i] > ratings[i-1] ) candy[i] = candy[i-1] + 1;
        }
        
        int sum = 0;
        
        for(int i=ratings.size()-1 ;i>0; i--){
            if( ratings[i-1] > ratings[i] ) candy[i-1] = max( candy[i-1], candy[i]+1 );
            sum += candy[i];
        }
        sum += candy[0];
        return sum;
    }
};