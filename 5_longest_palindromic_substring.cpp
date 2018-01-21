/*
	first
	一开始只想到最基础的完全遍历，利用所有可能的组合判断最长的回文，通过一些判断减少循环次数，比如如果当前字符长度小于当前最大回文，则直接跳过循环。

	思考利用一次遍历+判断来确定最大回问长度，利用最两个指针，head和back，循环利用back从0到str长度，每个循环通过判断当前是否为回文，如果为真，
	则head往前移动，如果为假则head往后移动，一次结束后back++。注意在每次真假判断之前head需要前移2，因为不能判断回文的长度是奇数还是偶数。
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
        // for(back<=s.size()){
        //     if(isPalindrome(s.substr(back-len,len))){
        //         if(len>max_len){
        //             max_head = back-len;
        //             max_len = len;
        //         }
        //         ++len;
        //         ++back;
        //     }
        //     else{
        //         len = back;
        //         while(len>=1){
        //             if(isPalindrome(s.substr(back-len,len))){
        //                 if(len>max_len){
        //                     max_head = back-len;
        //                     max_len = len;
        //                 }
        //                 ++back;
        //                 ++len;
        //                 break;
        //             }
        //             --len;
        //         }
        //     }
        // }
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