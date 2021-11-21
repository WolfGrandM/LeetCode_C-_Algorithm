/*
 * @lc app=leetcode.cn id=811 lang=cpp
 *
 * [811] 子域名访问计数
 */

// @lc code=start
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {

        typedef unordered_map<string,int> CountMap;
        CountMap time;
        for(int i=0; i<cpdomains.size(); i++){
            int j = 0,nowTime=0;
            while(cpdomains[i][j] != ' ')   j++;
            nowTime = stoi(cpdomains[i].substr(0,j));		//当前访问次数
            j++;
            while(j<cpdomains[i].length()){
                time[cpdomains[i].substr(j)] += nowTime;		//对每个字符名访问次数加上nowTime
                while(j<cpdomains[i].length() && cpdomains[i][j]!='.')  j++;
                j++;
            }
        }
        vector<string> ans;
        CountMap::iterator iter = time.begin();
        while(iter != time.end()){
            ans.push_back(to_string((*iter).second) + " " + (*iter).first);
            iter++;
        }
        return ans;
    }
};
// @lc code=end

