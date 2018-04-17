/*
	first
	首先想到利用二分法来查找。第二个版本尝试使用先搜索行，然后搜索列的方法，
*/

//version 1(13 ms)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()||matrix[0].empty()) return false;        
        if(target<matrix[0][0]||target>matrix[matrix.size()-1][matrix[0].size()-1]) return false;
        int head=0,back=matrix.size()*matrix[0].size();
        int row=matrix.size();
        int col = matrix[0].size();
        while(head<=back){
            int mid=head+(back-head)/2;
            if(matrix[mid/col][mid%col]<target) {
                head = mid+1;
            }
            else if(matrix[mid/col][mid%col]>target){
                back = mid-1;
            }
            else return true;
        }
        return false;
    }
};

//version 2(12ms)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()||matrix[0].empty()) return false;        
        if(target<matrix[0][0]||target>matrix[matrix.size()-1][matrix[0].size()-1]) return false;        
        int back=matrix.size()-1,head=0;
        int mid;
        while(head<=back){
            mid=head+(back-head)/2;
            if(matrix[mid][0]<target) {
                head = mid+1;
            }
            else if(matrix[mid][0]>target){
                back = mid-1;
            }
            else return true;
        }
        back= matrix[0].size()-1;
        head=0;
        int row = (matrix[mid][0]>target)?mid-1:mid;
        while(head<=back){
            mid = head+(back-head)/2;
            if(matrix[row][head]==target||matrix[row][back]==target) return true;
            if(matrix[row][mid]>target) back=mid-1;
            else if(matrix[row][mid]<target) head = mid+1;
            else return true;
        }
        return false;
    }
};