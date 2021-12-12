/*
 * @lc app=leetcode.cn id=771 lang=cpp
 *
 * [771] 宝石与石头
 */

// @lc code=start
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> set;
        int res=0;
        for(auto c:jewels){
            set.insert(c);
        }
        for(auto d:stones){
            if(set.count(d)){
                ++res;
            }
        }
        return res;
    }
};

// @lc code=end

