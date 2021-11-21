/*
 * @lc app=leetcode.cn id=685 lang=cpp
 *
 * [685] 冗余连接 II
 */

/*官方解法，每日抑题
  每次解困难题比解简单题还快
  因为简单题我还会试着写一写
  困难题，我看完题解，就直接复制粘贴了
  QAQ  */
// @lc code=start
struct UnionFind {
    vector <int> ancestor;

    UnionFind(int n) {
        ancestor.resize(n);
        for (int i = 0; i < n; ++i) {
            ancestor[i] = i;
        }
    }

    int find(int index) {
        return index == ancestor[index] ? index : ancestor[index] = find(ancestor[index]);
    }

    void merge(int u, int v) {
        ancestor[find(u)] = find(v);
    }
};

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        UnionFind uf = UnionFind(n + 1);
        auto parent = vector<int>(n + 1);
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
        int conflict = -1;
        int cycle = -1;
        for (int i = 0; i < n; ++i) {
            auto edge = edges[i];
            int node1 = edge[0], node2 = edge[1];
            if (parent[node2] != node2) {
                conflict = i;
            } else {
                parent[node2] = node1;
                if (uf.find(node1) == uf.find(node2)) {
                    cycle = i;
                } else {
                    uf.merge(node1, node2);
                }
            }
        }
        if (conflict < 0) {
            auto redundant = vector<int> {edges[cycle][0], edges[cycle][1]};
            return redundant;
        } else {
            auto conflictEdge = edges[conflict];
            if (cycle >= 0) {
                auto redundant = vector<int> {parent[conflictEdge[1]], conflictEdge[1]};
                return redundant;
            } else {
                auto redundant = vector<int> {conflictEdge[0], conflictEdge[1]};
                return redundant;
            }
        }
    }
};


作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/redundant-connection-ii/solution/rong-yu-lian-jie-ii-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
// @lc code=end

