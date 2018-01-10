/*
    first
    首先考虑到是DP问题，考虑到计算出之前的每一个点所拥有的路径，比如：对于坐标（i,j）这个点，通过加上（i-1，j）和（i，j-1）这两个点的path之和
    计算出当前点的路径，排除第一行和第一列（都为1）。
    优化：考虑到第一行和第一列可以直接置为1，可以消除每次循环中的判断。(实际上速度并没有优化，结果（3 ms）)

    看过discussion之后发现实质上这个数组为对称的，因此不用保持二维数组来计算，只需要采用一维数组就能够保存。(3 ms)

    看过discussion 发现可以直接采用数学的方法进行计算（排列组合思想）。复杂度O（n），由于需要进行乘法和除法计算，因此实际结果还是（3 ms）

    （貌似跑的系统变了，之前能0ms的结果现在需要3 ms。。orz）
*/
// version 1 (2 ms)
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==0||n==0) return 0;
        if(m==1||n==1) return 1;
        int path_num[m][n];
        path_num[0][0] = 1;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i!=0||j!=0) path_num[i][j]=0;
                if(j>0){
                    path_num[i][j] += path_num[i][j-1];
                }
                if(i>0){
                    path_num[i][j] += path_num[i-1][j];
                }
            }
        }
        
        return path_num[m-1][n-1];
    }
};

// version 2 (3 ms)
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==0||n==0) return 0;
        if(m==1||n==1) return 1;
        int path_num[m][n];
        path_num[0][0] = 1;
        
        for(int i=1;i<m;i++){
            path_num[i][0] = 1;
        }
        for(int j=1;j<n;j++){
            path_num[0][j] = 1;
        }
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                path_num[i][j]=0;
                path_num[i][j] += path_num[i][j-1];
                path_num[i][j] += path_num[i-1][j];
            }
        }
        
        return path_num[m-1][n-1];
    }
};


// copy from discussion （author：jianchaolifighter）
int uniquePaths(int m, int n) {
        if (m > n) return uniquePaths(n, m);
        vector<int> cur(m, 1);
        for (int j = 1; j < n; j++)
            for (int i = 1; i < m; i++)
                cur[i] += cur[i - 1]; 
        return cur[m - 1];
    }

//version 3
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==1||n==1) return 1;
        vector<int> ret(m,1);
        
        if(m<n) return uniquePaths(n,m);
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                ret[j] += ret[j-1];
            }
        }
        return ret[m-1];
    }
};
