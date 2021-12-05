/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        if(len == 0)
            return false;
        vector<int> memo(len,false);

        memo[len-1] = 1;
        for(int i=len-2;i>=0;i--){
            int furthestJump = min(i+nums[i],len-1);
            for(int j=furthestJump;j>i;j--){
                if(memo[j] == 1){
                    memo[i] = 1;
                    break;
                }
            }
        }

        return memo[0];
    }
};

// @lc code=end

