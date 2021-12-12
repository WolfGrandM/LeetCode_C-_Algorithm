/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution {
public:
vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        vector<int> res;
        int n=nums.size();
        deque<int> que;
        for(int i=0;i<n;i++)
        {
            while(que.size())
            {
                if(nums[i]>nums[que.back()])
                {
                    que.pop_back();
                }
                else
                {
                    break;
                }
            }
            que.push_back(i);
            if(i>=k-1)
            {
                if(i-que.front()==k)
                {
                    que.pop_front();
                }
                res.push_back(nums[que.front()]);
            }
        }
        return res;
    }
};
// @lc code=end

