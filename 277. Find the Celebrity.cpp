/*
	方法一：先找到一个满足条件的结果，然后问别的所有人是否知道他，
	方法二：进行小幅度优化
*/

//version 1(52 ms)
// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        if (n <= 1) return -1;
        int a = 0, b = 1;
        for (int i=0; i<n-1; i++) {
            if (knows(a, b)) {
                a = b; b++;
            } else {
                b++;
            }
        }
        
        for (int i=0; i<n; i++) {
            if (i != a && (!knows(i, a) || knows(a, i))) return -1;
        }
        return a;
    }
};

//version 2(36 ms)
// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        if (n <= 1) return -1;
        int a = 0;
        for (int i=1; i<n; i++) {
            if (knows(a, i)) a = i;
        }
        
        for (int i=0; i<n; i++) {
            if (i != a && (!knows(i, a) || knows(a, i))) return -1;
        }
        return a;
    }
};