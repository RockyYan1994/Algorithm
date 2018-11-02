/*
	方法一：采用sort之后，从前面遍历实现。
	方法二：不用sort，通过将citations映射到数组中，然后从后往前遍历实现。	
*/

//version 1(0 ms)
class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.empty()) return 0;
        int n = citations.size();
        sort(citations.begin(), citations.end());
        for (int i=0; i<n; i++) {
            if (citations[i] >= n-i ) return n-i;
        }
        return 0;
    }    
};

//version 2()
class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.empty()) return 0;
        int n = citations.size();
        vector<int> refs(n+1, 0);
        for (auto cit : citations) {
            if (cit > n) refs[n]++;
            else refs[cit]++;
        }
        int h = 0;
        for (int i=n; i>=0; i--) {
            h += refs[i];
            if (h >= i) return i;
        }
        return 0;
    }    
};