/*
 * @lc app=leetcode.cn id=709 lang=cpp
 *
 * [709] 转换成小写字母
 */

// @lc code=start
class Solution {
public:
   	bool isBigger(char c){		//判断字符是否为大写
        return c>='A'&&c<='Z';
    }
    string toLowerCase(string str) {
        int len = str.length();
        for(int i=0; i<len; i++){
            if(isBigger(str[i])){
                str[i] += 'a'-'A';
            }
        }
        return str;
    }

};
// @lc code=end

