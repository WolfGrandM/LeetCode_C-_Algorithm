/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 翻转字符串里的单词
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {

        string res;
        int i = 0;
        while(i < s.size()){
            while(i < s.size() && s[i] == ' ')  ++i;
            int j = i;
            while(j < s.size() && s[j] != ' ')  ++j;
            if(i != j)  res = s.substr(i, j-i) + " " + res;
            i = j+1;
        }
        return res.substr(0, res.size()-1);
    }
};
// @lc code=end

