/*
 * @lc app=leetcode.cn id=697 lang=cpp
 *
 * [697] 数组的度
 */

// @lc code=start
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        if(nums.empty()) return 0;
        // 定义统计哈希表和最大频数
        unordered_map<int, int> mp;
        int max_fre = 0;
        // 统计频数，并计算最大频数
        for(int i = 0; i < nums.size(); i ++) {
            mp[nums[i]] ++;
            max_fre = max(max_fre, mp[nums[i]]);
        }
        // 重构map
        mp.clear();
        // 定义窗口和满足频数的最短长度
        int ans = nums.size();
        int left = 0, right = 0;
        while(right < nums.size()) {
            mp[nums[right]] ++;
            // 频数达到要求后，移动左边界
            while(mp[nums[right]] == max_fre) {
                ans = min(ans, right - left + 1);
                mp[nums[left ++]] --;
            }
            right ++;
        }
        return ans;
    }
};
// @lc code=end

