/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        int length_p=p.length();
        int length_s=s.length();
        vector<int> res;
        if(length_p>length_s) return res;
        vector<int> temp_s(26,0),temp_p(26,0);
        for(int i=0;i<length_p;i++){
            temp_p[p[i]-'a']++;
            temp_s[s[i]-'a']++;
        }
        if(temp_p==temp_s) res.push_back(0);
        for(int i=0;i+length_p<length_s;i++){
            temp_s[s[i]-'a']--;
            temp_s[s[i+length_p]-'a']++;
            if(temp_p==temp_s){
                res.push_back(i+1);
            }
        }
        return res;
    }
};
// @lc code=end

