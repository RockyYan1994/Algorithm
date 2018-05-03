/*
把只包含因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，但14不是，因为它包含因子7。 
习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。
查看discussion之后，发现一个很简洁的想法，就是基于
1、每个丑数p，那么p*2，p*3, p*5依然是丑数
2、需要找到当前最小的丑数
那么采用DP，分别用三个变量来存储当前计算的丑数在数组中的位置。
*/

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if(index<7) return index;
        vector<int> ret(index);
        ret[0] = 1;
        int t2=0,t3=0,t5=0;
        for(int i=1;i<index;i++){
            ret[i] = min(ret[t2]*2,min(ret[t3]*3,ret[t5]*5));
            if(ret[i] == ret[t2]*2) t2++;
            if(ret[i] == ret[t3]*3) t3++;
            if(ret[i] == ret[t5]*5) t5++;
        }
        return ret[index-1];
    }
};