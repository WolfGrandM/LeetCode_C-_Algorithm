/*
 * @lc app=leetcode.cn id=516 lang=cpp
 *
 * [516] 最长回文子序列
 */

// @lc code=start
class Solution {
public:
      public int longestPalindromeSubseq(String s) {
        int[][]M = new int[s.length()][s.length()];
        for(int i = s.length()-1; i >= 0; i--){
            M[i][i] = 1;
            for (int j = i+1; j < s.length(); j++){
                if (s.charAt(j) == s.charAt(i)){
                    M[i][j] = M[i+1][j-1] + 2;
                } else {
                    M[i][j] = Math.max(M[i+1][j], M[i][j-1]);
                }
            }
        }
        return M[0][s.length()-1];
    }
};
// @lc code=end

