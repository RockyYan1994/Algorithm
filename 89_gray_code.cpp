/*
    first: 想到gray编码的特性，利用写出三个gray编码的变化，发现在n+1时，可以将之前的结果反转然后在之前的最高位前+1，
    最后将得到的结果加到res里面，不断重复直到n。
    00 01 -> 01 00 -> 11 10 -> 00 01 11 10
*/

//version 1(6 ms)
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res(1,0);
        if(n == 0) return res;
        res.push_back(1);
        for(int i=2;i<=n;i++){
            vector<int> temp = res;
            reverse(temp.begin(),temp.end());
            for(int j=0;j<temp.size();j++){
                temp[j] = temp[j] | (1<<(i-1)); 
            }
            res.insert(res.end(),temp.begin(),temp.end());
        }
        return res;
    }
};

//version 2(from jinrf in java)
public List<Integer> grayCode(int n) {
    List<Integer> result = new LinkedList<>();
    for (int i = 0; i < 1<<n; i++) result.add(i ^ i>>1);
    return result;
}