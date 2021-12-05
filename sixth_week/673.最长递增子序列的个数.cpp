/*
 * @lc app=leetcode.cn id=673 lang=cpp
 *
 * [673] 最长递增子序列的个数
 */

// @lc code=start
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return n;
        //f[i]存储的是以nums[i]为最大值的子序列长度以及该长度的序列的个数
        vector<pair<int, int>> f(n, {1,1});//初始化为1
        int max_len = 1;
        for(int i =1; i < n; ++i){
            for(int j = 0; j < i; ++j){
                if(nums[j] < nums[i]){
                    if(f[j].first +1 > f[i].first)
                        f[i] = {f[j].first+1, f[j].second};
                    else if(f[j].first+1 == f[i].first)//有多个最大值
                        f[i].second += f[j].second;//累加个数
                }
            }
            max_len = max(max_len, f[i].first);
        }
        int res = 0;
        for(const auto& c : f){//可能有多个最大长度
            if(c.first == max_len)  res += c.second;
        }
        return res;
    }
};

// @lc code=end

