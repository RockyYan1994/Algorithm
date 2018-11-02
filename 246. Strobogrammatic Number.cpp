/*

*/

class Solution {
public:
    bool isStrobogrammatic(string num) {
        for (int i=num.size()/2;i<num.size();i++) {
            if (num[i] == '0' || num[i] == '8' || num[i] == '1') {
                if (num[num.size()-i-1] != num[i]) return false;
            } else if (num[i] == '6') {
                if (num[num.size()-i-1] != '9') return false;
            } else if (num[i] == '9') {
                if (num[num.size()-i-1] != '6') return false;
            } else return false;
        }
        return true;
    }
};