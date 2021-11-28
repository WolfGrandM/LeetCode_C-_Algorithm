/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()||matrix[0].empty()) return false;
        int m=matrix.size(),n=matrix[0].size();
        int left=0;
        int right=m*n-1;
        while(left<right){
            int mid=left+right>>1;
            if(matrix[mid/n][mid%n]>=target){
                right=mid;
            }
            else{
                left=mid+1;
            }
        }
        if(matrix[left/n][left%n]==target) return true;
        return false;
    }
};

// @lc code=end

