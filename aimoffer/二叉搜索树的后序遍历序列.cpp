/*
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
根据后序遍历的规则，每一段都判断是否有前面一段小于最后一个元素和后面一段大于这个元素，这两段可以存在或者不存在，只要没有交叉，递归调用每一段。
第二个方法采用非递归的形式，但是时间复杂度为n^2.
*/

//version 1(4 ms)
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.empty()) return false;
        return isValid(sequence,0,sequence.size()-1);
    }
    bool isValid(vector<int> &sequence,int l, int r){
        if(l>=r) return true;
        int i=l;
        while(i<r && sequence[i]<sequence[r]) i++;
        for(int j=i+1;j<r;j++){
            if(sequence[j]<sequence[r]) return false;
        }
        return isValid(sequence,l,i-1)&&isValid(sequence,i,r-1);
    }
};

//version 2（3 ms）
链接：https://www.nowcoder.com/questionTerminal/a861533d45854474ac791d90e447bafd
来源：牛客网

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        int size = sequence.size();
        if(0==size)return false;
 
        int i = 0;
        while(--size)
        {
			while (sequence[i]<sequence[len]) i++;        
            while (sequence[i]>sequence[len]) i++;
 
            if(i<size)return false;
            i=0;
        }
        return true;
    }
};