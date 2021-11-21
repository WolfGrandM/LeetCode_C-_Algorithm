/*
 * @lc app=leetcode.cn id=1074 lang=cpp
 *
 * [1074] 元素和为目标值的子矩阵数量
 */

// @lc code=start
class Solution {
public:
    /*写得真好，我是想不出来这种解法，直接copy了*/
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> sum(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
        int ans = 0;
        for (int top = 1; top <= n; top++) {
            for (int bot = top; bot <= n; bot++) {
                int cur = 0;
                unordered_map<int, int> map;
                for (int r = 1; r <= m; r++) {
                    cur = sum[bot][r] - sum[top - 1][r];
                    if (cur == target) ans++;
                    if (map.count(cur - target)) ans += map[cur - target];
                    map[cur]++;
                }
            }
        }
        return ans;
    }
};


作者：AC_OIer
链接：https://leetcode-cn.com/problems/number-of-submatrices-that-sum-to-target/solution/gong-shui-san-xie-you-hua-mei-ju-de-ji-b-uttw/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
// @lc code=end

