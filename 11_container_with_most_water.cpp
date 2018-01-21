/*
    first
    首先只想到利用基础方法（复杂度O(n2)），想到在循环中加入一些判断，尽量减少执行的操作，但是结果还是超出程序运行时间。

    在查看discussion之后，发现可以采用一个从两边向中间收缩的方法，设置两个指针指向两端，然后每次比较两端的高度，比较短的一端移位一次，直到指针指向同一点
    优化方案：通过记录长度，减少计算面积的次数. 运行结果比优化前还慢。。惊了
*/

// version 1(out of time)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area=0;
        int ret = 0;
        for(int i=height.size()-1;i>=0;i--){
            int max_height = 0;
            for(int j=0;j<i;j++){
                int cur_height = min(height[i],height[j]);
                if(cur_height > max_height){
                    int temp_area = cur_height*(i-j);
                    if(temp_area > max_area) {
                        max_height = cur_height;
                        max_area = temp_area;
                    }
                }
            }
        }
        return max_area;
    }
};

// version 2(21 ms)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area=0;
        for(int i=0,j=height.size()-1;i<j;){
            max_area = max(max_area,(j-i) * min(height[i],height[j]));
            if(height[i]>height[j]) j--;
            else i++;
        }
        return max_area;
    }
};

//version 3(32 ms)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area=0;
        int cur_height = 0;
        for(int i=0,j=height.size()-1;i<j;){
            if(cur_height<min(height[i],height[j])){
                cur_height = min(height[i],height[j]);
                max_area = max(max_area,(j-i) * cur_height);
            }
            if(height[i]>height[j]) j--;
            else i++;
        }
        return max_area;
    }
};