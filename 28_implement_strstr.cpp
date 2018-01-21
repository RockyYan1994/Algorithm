/*
    first
    首先想到用两层循环来实现判定，外层遍历每一个开头，内层判断是否相等，结果非常慢，原因是外层循环的判定条件停止晚了。
    查看discussion之后，发现可以使用KMP算法（https://www.youtube.com/watch?v=GTJr8OvyEVQ）。
*/
//version 1 (712 ms) 修改判定后（7ms）
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size()==0) return 0;
        int res = -1;
        for(int i=0;i<haystack.size();i++){
            if(haystack[i]==needle[0]){
                res = i;
                for(int j=0;j<needle.size();j++){
                    if(haystack[i+j]!=needle[j]) {
                        res = -1; 
                        break;
                    }
                }
                if(res!=-1) break;
            }
        }
        return res;
    }
};

//version 2(35 ms)
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size()==0) return 0;
        int res = -1;
        for(int i=0;i<haystack.size();i++){
            if(haystack.compare(i,needle.size(),needle)==0) {
                res = i;
                break;
            }
        }
        return res;
    }
};

//version 3(6 ms)
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        int m = haystack.size(), n = needle.length();
        int res = -1;
        for(int i=0;i<m-n+1;i++){
            int j;
            for(j=0;j<n;j++){
                if(haystack[i+j]!=needle[j]) {
                    break;
                }
            }
            if(j == n) return i;
        }
        return -1;
    }
};