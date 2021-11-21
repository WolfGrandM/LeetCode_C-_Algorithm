/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
/*特意找了个递归解法以作参考，但自己写的时候总是超时，找了个思路接近的解法
    有时间找找到底是超时原因，这里先借用一下别人的解法 */
class Solution {
public:
	vector<vector<int>> ans;

	void trackback(vector<int>& nums, int start) {
		if (start == nums.size()) {
			ans.push_back(nums);
			return;
		}
		for (int i = start; i < nums.size(); i++) {
    		sort(nums.begin() + start, nums.end());  // 这里这里~~
			if (i > start && nums[i] == nums[i - 1]) continue;
			swap(nums[i], nums[start]);
			trackback(nums, start + 1);
			swap(nums[i], nums[start]);
		}
	}

	vector<vector<int>> permuteUnique(vector<int>& nums) {
		trackback(nums, 0);
		return ans;
	}
};


作者：zichang
链接：https://leetcode-cn.com/problems/permutations-ii/solution/c-jian-dan-qing-xi-zhi-yao-shao-shao-gai-rxgz/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
// @lc code=end

