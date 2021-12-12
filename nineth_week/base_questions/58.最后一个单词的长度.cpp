/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
	class Solution {
public:
    int lengthOfLastWord(string s)
    {
        int count=0;
        int len=s.size();
        for(int i=len-1;i>=0;i--)
        {
            if(s[i]!=' ')//不能用双引号
            {
                count++;
            }
            else if(count>0)
            {return count;}

            //如果第一个是空格的话，不做处理，继续往下遍历。

        }
        return count;
    }
};

// @lc code=end

