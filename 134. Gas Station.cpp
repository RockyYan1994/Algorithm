/*
	这个问题主要是需要定位开始的地方。主要利用性质：如果gas的总和大于cost的总和，那么就一定会有解。
*/

//version 1(6 ms)
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0;
        int start = 0, tank = 0;
        for(int i=0;i<cost.size();i++){
            if( (tank = tank + gas[i] - cost[i]) < 0 ){
                start = i+1;
                sum += tank;
                tank = 0;
            }
        }
        return sum + tank >= 0 ? start : -1; 
    }
};