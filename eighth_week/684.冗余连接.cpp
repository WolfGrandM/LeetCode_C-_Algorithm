/*
 * @lc app=leetcode.cn id=684 lang=cpp
 *
 * [684] 冗余连接
 */

// @lc code=start
class Solution {
public:
 int find(int x, vector<int>& parents)
    {
        if(x==parents[x])
        {
            return x;
        }
        else
        {
            return find(parents[x],parents);
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges)
    {
        int n=edges.size();
        vector<int> parents(n+1);
        for(int i=1;i<=n;i++)
        {
            parents[i]=i;
        }
        for(auto e:edges)
        {
            int x=e[0];
            int y=e[1];
            int s1=find(x,parents);
            int s2=find(y,parents);
            if(s1==s2)
            {
                return e;
            }
            else
            {
                parents[s1]=s2;
            }
        }
        return vector<int>();
    }
};
// @lc code=end

