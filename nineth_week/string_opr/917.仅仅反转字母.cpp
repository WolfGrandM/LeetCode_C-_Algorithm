/*
 * @lc app=leetcode.cn id=917 lang=cpp
 *
 * [917] 仅仅反转字母
 */

// @lc code=start
class Solution {
public:
    string reverseOnlyLetters(string S) {
        int l = 0, r = S.size()-1;
        while(l < r){
            while(l < S.size() && !isalpha(S[l]))  ++l;
            while(r >= 0 && !isalpha(S[r]))   --r;
            if(l < r)   swap(S[l++], S[r--]);
            else break;
        }
        return S;
    }
};

// @lc code=end

