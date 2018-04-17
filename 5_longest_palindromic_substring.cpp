/*
	first
	一开始只想到最基础的完全遍历，利用所有可能的组合判断最长的回文，通过一些判断减少循环次数，比如如果当前字符长度小于当前最大回文，则直接跳过循环。

	思考利用一次遍历+判断来确定最大回问长度，利用最两个指针，head和back，循环利用back从0到str长度，每个循环通过判断当前是否为回文，如果为真，
	则head往前移动，如果为假则head往后移动，一次结束后back++。注意在每次真假判断之前head需要前移2，因为不能判断回文的长度是奇数还是偶数。

	查看discussion之后，发现可以使用DP和从中间往两边的遍历方法。
	version 3 是从头遍历，遍历到的每个元素从中间展开，看是否为回文，在判断的过程中，首先通过一个循环来把重复的元素过滤掉，然后进行判断。
	DP主要采用的是记录每个pair是否为回文，然后下一个判断只需要使用上一个判断的结果即可。
*/
//version1 (883 ms)
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty()) return s;
        //size_t back=1,len=1;
        int max_head=0,max_len=1;
        for(int i=1;i<=s.size();++i){
            for(int j=i;j>=1;--j){
                if(j<=max_len) break;
                if(isPalindrome(s.substr(i-j,j))){
                    if(j>max_len){
                        max_head = i-j;
                        max_len = j;
                        break;
                    }
                }
            }
        }
        return s.substr(max_head,max_len);
    }
    
    bool isPalindrome(string subs){
        for(int i=0;i<subs.size()/2;i++){
            if(subs[i]!=subs[subs.size()-i-1]) return false;
        }
        return true;
    }
};

//version 2(16 ms)
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty()) return s;
        int head=0,back=1;
        int max_head=0,max_back=1;
        
        while(back<=s.size()){
            if(isPalindrome(s.substr(head,back-head))){
                if(back-head>max_back-max_head){
                    max_head = head;
                    max_back = back;
                }
                if(head>0) --head;
                while(head!=0&&isPalindrome(s.substr(--head,back-head))){
                    if(back-head>max_back-max_head){
                        max_head = head;
                        max_back = back;
                    }
                    if(head==0) break;
                }
                ++back;
            }
            else{
                if(head>0) --head;
                while(back-head>=1){
                    if(isPalindrome(s.substr(head,back-head))){
                        if(back-head>max_back-max_head){
                            max_head = head;
                            max_back = back;
                        }
                        ++back;
                        break;
                    }
                    else ++head;
                }
            }
        }
        return s.substr(max_head,max_back-max_head);
    }
    
    bool isPalindrome(string subs){
        for(int i=0;i<subs.size()/2;i++){
            if(subs[i]!=subs[subs.size()-i-1]) return false;
        }
        return true;
    }
};

//version 3(10 ms)
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty()) return s;
        int max_head=0,max_len=1;
        for(int i=0;i<s.size();i++){
            if(s.size()-i<=max_len/2) break;
            int j=i,k=i;
            while(s[j+1]==s[j]) ++j;
            while(s[j+1]==s[k-1] && (j+1<s.size()&&k-1>=0)){
                j++;
                k--;
            }
            if(j-k+1>max_len) {
                max_head = k;
                max_len = j-k+1;
            }
        }
        return s.substr(max_head,max_len);
    }
};

//version 4(143 ms)
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty()) return s;
        int max_head=0,max_len=1;
        vector<vector<bool> > dp_map(s.size(),vector<bool>(s.size(),false));
        
        for(int i=s.size()-1;i>=0;i--){
            for(int j=i;j<s.size();j++){
                dp_map[i][j] = s[i]==s[j] && (j-i<3 || dp_map[i+1][j-1]);
                
                if(j-i+1>max_len&&dp_map[i][j]){
                    max_head = i;
                    max_len = j-i+1;
                }
            }
        }
        return s.substr(max_head,max_len);
    }
};