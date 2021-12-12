/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        map<char,int> sMat;
        for(int i = 0; i < s.size(); i++){
            sMat[s[i]]++;
        }
        for(int i = 0; i < t.size(); i++){
            sMat[t[i]]--;
        }
        for(int i = 0; i < t.size(); i++){
            if(sMat[t[i]] != 0)
                return false;
        }
        return true;
    }
};
// @lc code=end

