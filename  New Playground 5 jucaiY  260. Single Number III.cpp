/*
	方法一：用map
	方法二：通过异或特性，然后用diff &= -diff 找到第一个不同的bit位置，然后进行分别异或。
*/

//version 1(8 ms)
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (auto num : nums) {
            mp[num]++;
        }
        vector<int> res;
        for (auto entry : mp) {
            if (entry.second == 1) res.push_back(entry.first);
        }
        return res;
    }
};

//version 2()
class Solution
{
public:
    vector<int> singleNumber(vector<int>& nums) 
    {
        // Pass 1 : 
        // Get the XOR of the two numbers we need to find
        int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        // Get its last set bit
        diff &= -diff;

        // Pass 2 :
        vector<int> rets = {0, 0}; // this vector stores the two numbers we will return
        for (int num : nums)
        {
            if ((num & diff) == 0) // the bit is not set
            {
                rets[0] ^= num;
            }
            else // the bit is set
            {
                rets[1] ^= num;
            }
        }
        return rets;
    }
};