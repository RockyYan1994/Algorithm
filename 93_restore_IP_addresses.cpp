/*
	first: 查看了discussion之后发现，可以直接采用4个for循环遍历所有情况的方式来找出所有可能性，然后对每个可能性进行判断，满足条件的就输出。
	也可以用backtracking的方法来实现，不过代码复杂一点。
*/


//version 1(3ms)
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        for(int i=1;i<4;i++){
            for(int j=1;j<4;j++){
                for(int m=1;m<4;m++){
                    for(int n=1;n<4;n++){
                        if(i+j+m+n != s.size()) continue;
                        int a = stoi(s.substr(0,i));
                        int b = stoi(s.substr(i,j));
                        int c = stoi(s.substr(i+j,m));
                        int d = stoi(s.substr(i+j+m,n));
                        if(a<=255 && b<=255 && c<=255 && d<=255){
                            string str = to_string(a)+'.'+to_string(b)+'.'+to_string(c)+'.'+to_string(d);
                            res.push_back(str);
                        }
                    }
                }
            }
        }
        return res;
    }
    
};