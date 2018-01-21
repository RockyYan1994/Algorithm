class Solution {
/*
    first
    这道题有毒可能

    考虑到第一个实现在for循环采用了大量的if判断条件，优化思路主要就是将if提取出来，在进入for循环之前先处理一部分，除了必须留在for循环的判定。
*/
// version 1（30 ms）
public:
    int myAtoi(string str) {
        int ret=0;
        bool sign = true;
        int count_sign = 0;
        int valid = 0;
        for(int i=0;i<str.length();i++){
            if(str[i]=='-') {
                count_sign++;
                valid++;
                sign = false;
                continue;
            }
            if(str[i]=='+'){
                count_sign++;
                valid++;
                continue;
            }

            if(str[i]>='0' && str[i]<='9') valid++;
            if(valid!=0 && (str[i]<'0'||str[i]>'9') ) break;
            if(str[i]==' ') continue;
            if(str[i]<'0'||str[i]>'9') return 0;
            
            int temp = ret*10 + (int)(str[i]-'0');
            if((temp/10!=ret)&&sign) {
                return INT_MAX;
            }
            if((temp/10!=ret)&&!sign){
                return INT_MIN;
            }
            ret = temp;
            
        }
        if(count_sign>1) return 0;
        if(!sign) ret = -ret;
        
        
        
        return ret;
    }
};
//version 2(22 ms)
class Solution {
public:
    int myAtoi(string str) {
        int ret=0;
        bool sign = true;
        int count_sign = 0;
        int valid = 0;
        int i=0;
        for(;i<str.length();i++){
            if(str[i]!=' ') break;
        }
        
        if(str[i]=='-') {
            valid++;
            sign = false;
            i++;
        }
        else if(str[i]=='+'){
            valid++;
            i++;
        }
        
        for(;i<str.length();i++){
            if(str[i]>='0' && str[i]<='9') valid++;
            if(valid!=0 && (str[i]<'0'||str[i]>'9') ) break;
            // if(str[i]==' ') continue;
            if(str[i]<'0'||str[i]>'9') return 0;
            
            int temp = ret*10 + (int)(str[i]-'0');
            if(temp/10!=ret) {
                return sign?INT_MAX:INT_MIN;
            }
            ret = temp;
            
        }
        // if(count_sign>1) return 0;
        if(!sign) ret = -ret;
        
        
        
        return ret;
    }
};