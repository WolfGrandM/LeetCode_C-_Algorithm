/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */

// @lc code=start
class Solution {
public:
        vector<int> res;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    	//依赖关系抽象成有向图
        vector<vector<int>> adj(numCourses);//邻接表
        vector<int> indegree(numCourses);//入度
        for(const auto &v : prerequisites){
            adj[v[1]].push_back(v[0]);//v[1]指向v[0]
            ++indegree[v[0]];
        }
        queue<int> q;
        for(int i = 0; i < numCourses; ++i){//起点的入度为0，任意一个入度为0的都能作为起点
            if(indegree[i] == 0)    q.push(i);
        }
        while(!q.empty()){
            int v = q.front();
            res.push_back(v);
            q.pop();
            for(const auto &w : adj[v]){
                --indegree[w];
                if(indegree[w] == 0)	q.push(w);//当该门课的先决条件都已达成
            }
        }
        return res.size() == numCourses ? res : vector<int>();
    }
};
// @lc code=end

