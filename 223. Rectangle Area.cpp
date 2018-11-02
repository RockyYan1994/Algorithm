/*

*/

//version 1
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int left = max(A, E);
        int right = min(C, G);
        int top = min(D, H);
        int bottom = max(B, F);
        int area = (C-A) * (D-B) + (G-E) * (H-F);
        if(left < right && bottom < top) area -= (right-left) * (top-bottom);
        return area;
    }
};