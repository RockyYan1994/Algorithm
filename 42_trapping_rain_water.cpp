/*

*/


class Solution {
public:
    int trap(vector<int>& height) {
        int sum = 0;
        int left = 0,
        for(int i=0;i<height.size();i++){
            int right = i;
            if(height[i]>=height[left]){
                int temp = 0;
                for(int j=left+1;j<i;j++){
                    temp += height[left]-height[j];
                }
                sum+=temp;
                left = i;
            }
            if(height[i]<height[left]&&left==i-1)
        }
    }
};