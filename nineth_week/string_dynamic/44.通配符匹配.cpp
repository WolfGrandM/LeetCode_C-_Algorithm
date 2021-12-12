/*
 * @lc app=leetcode.cn id=44 lang=cpp
 *
 * [44] 通配符匹配
 */

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        int j=0;//定义在外面，循环体外要用
        for(int i=0,last_p=0,s_start=0;i<s.size();)
        {
            if(j<p.size()&&(s[i]==p[j]||p[j]=='?'))//
            {
                i++;
                j++;
            }
            else if(j<p.size()&&p[j]=='*')
            {
                s_start=i;
                last_p=++j;
            }
            else if(last_p!=0)
            {
                i=s_start++;
                j=last_p;
            }
            else
                return false;
        }
        for(;j<p.size()&&p[j]=='*';++j);
        return j==p.size();
    }
};


// @lc code=end

