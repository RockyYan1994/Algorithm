/*
	first
	首先想到采用将每个位置的点采用数字运算，每次运算完成之后再转换成为char的方式，直到遍历玩整个string，但是跑出来的结果非常的慢，结果发现是写了一个cout没删除。，
	查看完discussion之后发现，可以直接通过string加法的方式来更新string，这样可以让算法更 简洁。
*/

//version 1(4 ms)
class Solution {
public:
    string addBinary(string a, string b) {
        int sum=0;
        int a_size = a.size()-1, b_size=b.size()-1;
        string res(max(a.size(),b.size()),'0');
        while(a_size>=0||b_size>=0){
            sum = sum + ((a_size>=0)?a[a_size]-'0':0)+((b_size>=0)?b[b_size]-'0':0);
            cout<<sum<<" a size "<<a_size<<" b size "<<b_size<<endl;
            res[max(a_size--,b_size--)] = sum%2+'0';
            sum = sum >> 1;
        }
        if(sum==1){
            res.insert(res.begin(),'1');
        }
        return res;
    }
};

//version 2(4 ms)
class Solution {
public:
    string addBinary(string a, string b) {
        int sum=0;
        int a_size = a.size()-1, b_size=b.size()-1;
        string res;
        while(a_size>=0||b_size>=0||sum==1){
            sum = sum + ((a_size>=0)?a[a_size--]-'0':0)+((b_size>=0)?b[b_size--]-'0':0);
            res = (char)(sum%2+'0')+res;
            sum = sum >> 1;
        }
        return res;
    }
};