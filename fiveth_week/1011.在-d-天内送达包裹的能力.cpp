/*
 * @lc app=leetcode.cn id=1011 lang=cpp
 *
 * [1011] 在 D 天内送达包裹的能力
 */

// @lc code=start
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D)
    {
        int n=weights.size();
        int left=*max_element(weights.begin(),weights.end());
        int right=accumulate(weights.begin(),weights.end(),0);
        int res=left;
        while(left<=right)
        {
            int mid=(left+right)/2;
            int count=0;
            int sum=0;
            for(int i=0;i<n;i++)
            {
                sum+=weights[i];
                if(sum>mid)
                {
                    count++;
                    sum=weights[i];
                }
            }
            count++;
            if(count<=D)
            {
                res=mid;
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }
        return res;
    }
};
// @lc code=end

