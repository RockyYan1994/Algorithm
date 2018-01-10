//  first
/*
    首先考虑到需要通过计算的方法来得出序列，一开始想到通过k除阶乘的方法直接得出数字，但是由于每次计算后数字-1的情况，只能通过计算得出数字的position
    。因此采用直接计算位置的方法。
    优化思路：避免进行int到string的转换，直接使用string进行操作，通过计算出位置可以直接将结果push进一个string序列，避免int类型的计算。

    看了discussion之后，发现可以直接用rotation来实现对string的操作，因此可以只采用一个string来实现，不用先创建一个string，然后用rotation来实现。
    实现rotation需要使用两个int变量作为指针（i，j）。首先通过计算得出应该置于当前位置头的指针pos， 然后将j指向该位置的元素，保存，将前面的元素后移，
    最后将该位置元素放置在当前最前方。
*/

// version 1 (7ms)
class Solution {
public:
    string getPermutation(int n, int k) {
        int temp_pos = 0;
        int temp_num = 0;
        int fac[9];
        fac[0] = 1;
        int temp_fac = 1;
        vector<int> num_queue;
        k--;
        for(int i=1;i<=n;i++){
            num_queue.push_back(i);
        }
        for(int i=1;i<9;i++){
            temp_fac *= i;
            fac[i] = temp_fac;
        }
        for(int i=n;i>=1;i--){
            temp_pos = k / fac[i-1];
            temp_num = temp_num*10 + num_queue[temp_pos];
            num_queue.erase(num_queue.begin()+temp_pos);
            k = k - temp_pos * fac[i-1];
        }
        
        stringstream ss;
        ss<<temp_num;
        string ret;
        ss>>ret;
        return ret;
    }
};

// version 2 (6ms)
class Solution {
public:
    string getPermutation(int n, int k) {
        int temp_pos = 0;
        int fac[9];
        fac[0] = 1;
        int temp_fac = 1;
        string ret;
        string str_queue;
        k--;
        for(int i=1;i<=n;i++){
            str_queue.push_back(i+'0');
        }
        for(int i=1;i<n;i++){
            temp_fac *= i;
            fac[i] = temp_fac;
        }
        for(int i=n;i>=1;i--){
            temp_pos = k / fac[i-1];
            ret.push_back(str_queue[temp_pos]);
            str_queue.erase(str_queue.begin()+temp_pos);
            k = k - temp_pos * fac[i-1];
        }

        return ret;
    }
};

// version 3 (3ms)
class Solution {
public:
    string getPermutation(int n, int k) {
        int i,j ;
        int fac[9];
        fac[0] = 1;
        int temp_fac = 1;
        string ret(n,'0');
        k--;
        for(int i=0;i<n;i++){
            ret[i] += i+1;
        }
        for(int i=1;i<n;i++){
            temp_fac *= i;
            fac[i] = temp_fac;
        }
        for(i=0;i<n;i++){
            j = i + k / fac[n-i-1];
            char c = ret[j];
            for(;j>i;j--){
                ret[j] = ret[j-1];
            }
            ret[i] = c;
            k = k % fac[n-i-1];
        }

        return ret;
    }
};