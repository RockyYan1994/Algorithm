/*
	方法一：还是采用一个sums数组记录，但是要注意更新的时间复杂度是O(n)，因为要更新i后所有的sums。
	方法二：通过分成sqrt(n)来实现。可以降到复杂度O(sqrt(n))。https://leetcode.com/problems/range-sum-query-mutable/solution/
	方法三：实用segment tree
	方法四：采用binary indexed tree
*/

//version 1(92 ms)
class NumArray {
    vector<int> sums;
public:
    NumArray(vector<int> nums) {
        sums.push_back(0);
        for (int i=0; i<nums.size(); i++) {
            sums.push_back(nums[i] + sums[i]);
        }
    }
    
    void update(int i, int val) {
        int diff = val - (sums[i+1] - sums[i]);
        for (int k = i+1; k<sums.size(); k++) {
            sums[k] += diff;
        }
    }
    
    int sumRange(int i, int j) {
        return sums[j+1] - sums[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */

//version 3()
class NumArray {
    vector<int> tree;
    int n;
    
    void buildTree(vector<int>& nums) {
        for (int i=0; i<n; i++) {
            tree[i+n] = nums[i];
        }
        for (int i=n-1; i>0; i--) {
            tree[i] = tree[2*i] + tree[2*i + 1];
            cout << "tree[" << i <<"] is :" << tree[i] << endl;
        }
    }
public:
    NumArray(vector<int> nums) {
        if (nums.size() > 0) {
            n = nums.size();
            tree = vector<int>(2*n, 0);
            buildTree(nums);
        }        
    }
    
    void update(int i, int val) {                  
        int pos = i + n;
        tree[pos] = val;
        while (pos > 0) {
            int l = pos;
            int r = pos;
            if (pos % 2==0) {
                r += 1;
            } else {
                l -= 1;
            }
            pos /= 2;
            tree[pos] = tree[l] + tree[r];            
        }
    }
    
    int sumRange(int i, int j) {
        int l = i+n, r = j+n;
        int sum = 0;
        while (l <= r) {
            if (l % 2 == 1) {
                sum += tree[l];
                l++;
            } 
            if (r % 2 == 0) {
                sum += tree[r];
                r--;
            }
            l /= 2;
            r /= 2;            
        }
        return sum;
    }
};

//version 4()
class NumArray {
    vector<int> BITree;
    vector<int> nums;
    int n;

    int getSum(int i) {
        int sum = 0, idx = i + 1;
        while (idx > 0) {
            sum += BITree[idx];
            idx -= idx&(-idx);
        }
        return sum;
    }
    
    void updateBITree(int i, int val) {
        int idx = i + 1;
        while (idx <= n) {
            BITree[idx] += val;
            idx += (idx&(-idx));
        }
    }
    
public:
    NumArray(vector<int> nums) {
        this->nums = nums;
        n = nums.size() + 1;
        BITree = vector<int>(n, 0);
        for (int i=0; i<nums.size(); i++) {
            updateBITree(i, nums[i]);
        }
    }
    
    void update(int i, int val) {        
        updateBITree(i, val - nums[i]);   
        nums[i] = val;
    }
    
    int sumRange(int i, int j) {
        return i == 0 ? getSum(j) : getSum(j) - getSum(i-1);        
    }
};