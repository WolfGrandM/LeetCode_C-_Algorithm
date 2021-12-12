/*
 * @lc app=leetcode.cn id=699 lang=cpp
 *
 * [699] 掉落的方块
 */

// @lc code=start
class Solution {
public:
	vector<int> fallingSquares(vector<vector<int>>& positions) {
        int n = positions.size();
        vector<int> pHeight(n,0);
        for(int i=0; i<n; i++){
            int left = positions[i][0];
            int right = positions[i][0]+positions[i][1];
            pHeight[i] += positions[i][1];
            for(int j=i+1; j<n; j++){
                if(left<positions[j][1]+positions[j][0] && right>positions[j][0]){		//第j块方块会落到第i块方块上面，因此其实高度可能发生改变
                    pHeight[j] = max(pHeight[j],pHeight[i]);
                }
            }
        }
        vector<int> ans(n,0);
        int cur=0;
        for(int i=0; i<n; i++){
            cur = max(cur,pHeight[i]);		//记录已知的最大高度
            ans[i] = cur;
        }
        return ans;
    }

};
// @lc code=end

