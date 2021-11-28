/*
 * @lc app=leetcode.cn id=875 lang=cpp
 *
 * [875] 爱吃香蕉的珂珂
 */

// @lc code=start
class Solution {
public:
    bool possible(vector<int>& piles, int H, int mid)
    {
        int sum = 0;
        for(int i=0;i<piles.size();i++)
        {
            sum+=piles[i]%mid==0?piles[i]/mid:piles[i]/mid+1;
        }
        return sum<=H;
    }

    int minEatingSpeed(vector<int>& piles, int H) {
        // int max1 = 0;
        // for(int i=0;i<piles.size();i++)
        // {
        //     max1 = max(max1,piles[i]);
        // }
        sort(piles.begin(),piles.end());
        int len = piles.size();
        int max1 = piles[len-1];
        int l = 1,r = max1;
        while(l<r)
        {
            int mid = l+(r-l)/2;
            if(possible(piles,H,mid))
            {
                r = mid;
            }
            else
            {
                l = mid+1;
            }
        }
        return l;
    }
};
// @lc code=end

