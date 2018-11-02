/*
	主要注意几个点：
	1. 使用long避免超过长度问题。
	2. 注意符号问题。
	3. 验证重复问题。
*/

//verison 1(0 ms)
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0 || denominator == 0) return "0";
        string res = "";
        if(numerator>0 ^ denominator>0) res += "-";
        long numer = numerator>0 ? (long)numerator : (long)numerator * (-1);
        long denom = denominator>0 ? (long)denominator : (long)denominator * (-1);
        long num = numer / denom;
        res += to_string(num);
        long rmd = numer % denom;
        if(!rmd) return res;
        res += ".";
        unordered_map<long, long> mp;
        rmd *= 10;
        while(rmd) {
            long temp = rmd / denom;
            if(mp.find(rmd) != mp.end()) {
                res.insert(mp[rmd], 1, '(');
                res += ")";
                break;
            }
            mp[rmd] = res.size();
            res += to_string(temp);
            rmd = (rmd%denom) * 10;
        }
        return res;
    }
};