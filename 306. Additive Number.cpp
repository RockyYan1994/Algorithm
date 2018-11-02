/*
	方法一：直接用DFS实现，但是不能处理数字过长的情况。需要用string的数字比较
*/

//version 1()
class Solution {
public:
    bool isAdditiveNumber(string num) {
        if (num.size() < 3) return false;
        return backtracking(num, 0, 0, 0);
    }
    
    bool backtracking(string num, int idx, long pre1, long pre2) {
        if (idx == num.size()) return true;
        if (num[idx] == '0') return false;
        for (int i=idx+1; i<=num.size(); i++) {
            int cur = stol(num.substr(idx, i-idx));
            if ((!pre1 || !pre2 || cur == pre1 + pre2) && backtracking(num, i, pre2, cur)) return true; 
        }
        return false;
    }
};

//version 2(0 ms)
class Solution {
public:
        bool isAdditiveNumber(string num) {
            for(int i=1; i<=num.size()/2; i++){
                for(int j=1; j<=(num.size()-i)/2; j++){
                    if(check(num.substr(0,i), num.substr(i,j), num.substr(i+j))) return true;
                }
            }
            return false;
        }
        bool check(string num1, string num2, string num){
            if(num1.size()>1 && num1[0]=='0' || num2.size()>1 && num2[0]=='0') return false;
            string sum=addHelper(num1, num2);
            if(num==sum) return true;
            if(num.size()<=sum.size() || sum.compare(num.substr(0,sum.size()))!=0) return false;
            else return check(num2, sum, num.substr(sum.size()));
        } 
        string addHelper(string num1, string num2) {
            string res;
            int m = num1.size()-1, n = num2.size()-1, add = 0;
            while (m>=0 || n>=0 || add) {
                int cur = add + (m>=0 ? (num1[m--] - '0') : 0) + (n>=0 ? (num2[n--] - '0') : 0) ;
                res += to_string(cur%10);
                add = cur/10;
            }
            reverse(res.begin(), res.end());
            return res;
        }
    };