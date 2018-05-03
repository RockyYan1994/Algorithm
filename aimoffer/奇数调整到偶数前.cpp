/*
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，
所有的偶数位于位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
首先想使用空间O(1)的方法，也可以使用冒泡排序类似的方法或者使用额外数组。
*/

//version 1(3 ms)
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int count = 0;
        int odd_pos = 0;
        for(int i=array.size()-1;i>=0;i--){
            if(array[i]%2 == 1) {
                count++;
                odd_pos = i;
            }
            else{
                if(odd_pos>i){
                    for(int j=i;j<i+count;j++){
                        swap(array[j],array[j+1]);
                    }
                }
            }
        }
    }
};