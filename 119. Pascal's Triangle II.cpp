/*
	一开始采用正向的方法，想通过一个temp变量来记录改变前的状态，但是始终没有调整对，查看discussion之后，发现通过从后往前更新每一层的方法可以避免修改
	前面的数据。
	写出反向之后发现正向也可以实现，不过需要在修改ret[j]之前先保存之前的ret[j]。
*/

//version 1(3 ms)
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ret(rowIndex+1,1);
        if(rowIndex == 0) return ret;
        for(int i=1;i<=rowIndex;i++){
        	int temp = ret[0];
        	for(int j=i-1;j>=1;j--) {
        		ret[j] = ret[j-1] + ret[j];
        	}
        }
        return ret;
    }
};

//version 2(3 ms)
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ret(rowIndex+1,1);
        if(rowIndex == 0) return ret;
        for(int i=1;i<=rowIndex;i++){
        	int temp = ret[0];
        	for(int j=1;j<i;j++) {
                int x = ret[j];
        		ret[j] = temp + ret[j];
                temp = x;
        	}
        }
        return ret;
    }
};