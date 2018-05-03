/*
在一个长度为n的数组里的所有数字都在0到n-1的范围内。 数组中某些数字是重复的，但不知道有几个数字是重复的。
也不知道每个数字重复几次。请找出数组中任意一个重复的数字。 例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是第一个重复的数字2。
首先先到使用hashmap的方法来实现，空间复杂度相对比较高。
查看了discussion发现还可以使用一个bool数组来实现，因为限定了范围。
还可以用常数的空间来实现,这个方法主要利用的是一个特性，由于所有值都小于等于n-1，因此可以用索引代表值。从numbers第一个元素遍历，将numbers[i]对应的
元素+length，这样往下面遍历的时候，如果numbers[i]==numbers[j]并且i<j，那么当第二次j遍历的时候，numbers[j]已经大于length，这样能确定已经重复。
*/

//version 1(4 ms)
class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        unordered_map<int,int> um;
        for(int i=0;i<length;i++){
            unordered_map<int,int>::iterator it = um.find(numbers[i]);
            if(it != um.end()) {
                *duplication = numbers[i];
                return true;
            }else{
                um[numbers[i]] = 1;
            }
        }
        return false;
    }
};

//version 2(3 ms)
class Solution {
public:
    bool duplicate(int numbers[], int length, int* duplication) {
        int index;
        for(int i=0;i<length;i++){
            index = numbers[i];
            if(index>=length) index-=length;
            if(numbers[index] >= length) { *duplication = index; return true; }
            numbers[index] += length;
        }
        return false;
    }
};