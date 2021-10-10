/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 */

// @lc code=start
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {


                if (matrix.size() == 0) {
            return 0;
        }
        int maxarea = 0;
        int dp[matrix.size()][matrix[0].size()];
        memset(dp, 0, sizeof(dp));  //  初始化为0

        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = j == 0 ? 1 : dp[i][j - 1] + 1;           //  dp,计算宽度
                    int width = dp[i][j];

                    for (int k = i; k >= 0; k--) {
                        width = min(width, dp[k][j]);                   //  向上每次取该行向下最短宽
                        maxarea = max(maxarea, width * (i - k + 1));    //  最短宽 * 高度
                    }
                }
            }
        }
        return maxarea;
    }
};
// @lc code=end

