
/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> result;

        for(auto str : strs) {
            auto tempStr = str;
            sort(tempStr.begin(), tempStr.end());
            mp[tempStr].push_back(str);
        }

        for(auto elem : mp) {
            result.push_back(elem.second);
        }
        return result;
    }
};
// @lc code=end

