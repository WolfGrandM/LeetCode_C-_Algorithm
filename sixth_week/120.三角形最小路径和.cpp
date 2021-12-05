/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */

// @lc code=start
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> minNums = triangle[triangle.size() - 1];
        for (int i = triangle.size() - 2; i >= 0; -- i)
            for (int j = 0; j <= i; ++ j)
                minNums[j] = (minNums[j] < minNums[j + 1] ? minNums[j] : minNums[j + 1])
                        + triangle[i][j];
        return minNums[0];
    }
};
// @lc code=end

