/*
想到只使用栈和或者用number+count的方法，并且只过一次，但是发现不行。必须验证

*/

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int number = 0,count = 1;
        for(auto n : numbers){
            if(n == number) count++;
            else{
                if(count == 1) { 
                    number = n;
                }
                else count--;
            }
        }
        count = 0;
        for(auto n : numbers){
            if(number == n) count++;
        }
        if(count>numbers.size()/2) return number;
        return 0;
    }
};