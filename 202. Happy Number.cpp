/*
	1，使用fast和slow两个变量来进行happy number的计算，如果两个相等且不等于1，那么返回false，如果某一个返回1，则return true
	2，采用hashmap来标记，如果某一个数已出现，则返回false
*/

//version 1(4 ms)
class Solution {
public:
    bool isHappy(int n) {
        int fast = n, slow = n;
        int sum1 = 0, sum2 = 0;
        do{
            fast = happyHelper(fast);
            fast = happyHelper(fast);
            slow = happyHelper(slow);
        }while(fast!=slow && slow!=1);
        return slow == 1;
    }
    int happyHelper(int num){
        int sum = 0;
        while(num){
            int digit = num%10;
            sum += digit * digit;
            num /= 10;
        }
        return sum;
    }
};

//version 2(4 ms)
class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,int> m;
        while(true){
            int sum = 0;
            while(n){
                int digit = n%10;
                sum += digit * digit;
                n /= 10;
            }
            n = sum;
            if(m[n]++ > 0) break;
            if(n == 1) return true;
        }
        return false;
    }
};