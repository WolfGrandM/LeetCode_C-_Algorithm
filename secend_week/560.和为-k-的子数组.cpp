/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> sumCount;
        sumCount[0]=1;
        int sum=0,count=0;
        for (size_t i = 0; i < nums.size(); i++)
        {
            sum+=nums[i];
            if(sumCount.find(sum-k)!=sumCount.end()) {
                count+=sumCount[sum-k];
            }
            sumCount[sum]++;
        }
        return count;

    }
};
// @lc code=end

