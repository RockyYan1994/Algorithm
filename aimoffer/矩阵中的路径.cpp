/*
请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一个格子开始，
每一步可以在矩阵中向左，向右，向上，向下移动一个格子。如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。 
例如 a b c e s f c s a d e e 矩阵中包含一条字符串"bcced"的路径，但是矩阵中不包含"abcb"路径，
因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。

这道题主要思路是采用backtracking 的方法，通过对每个点当作开始，然后进行backtracking的遍历，找出符合的点就return true。
*/

//version 1(3 ms)
class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        bool *flag = new bool[rows*cols];
        memset(flag,false,rows*cols);
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(found(matrix,rows,cols,str,0,i,j,flag)) {
                    delete[] flag;
                    return true;
                }
            }
        }
        delete[] flag;
        return false;
    }
    bool found(char* matrix, int rows,int cols,char* str,int k, int i, int j, bool* flag){
        int index = i*cols+j;
        if(i<0 || j<0 || i>=rows || j>=cols || str[k] != matrix[index] || flag[index]) return false;
        if(str[k+1]=='\0') return true;
        flag[index] = true;
        if(  found(matrix,rows,cols,str,k+1,i+1,j,flag)
           ||found(matrix,rows,cols,str,k+1,i-1,j,flag)
           ||found(matrix,rows,cols,str,k+1,i,j+1,flag)
           ||found(matrix,rows,cols,str,k+1,i,j-1,flag)) return true;
        flag[index] = false;
        return false;
    }

};