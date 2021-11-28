/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
class Solution {
public:
    vector<vector<bool>> st;
    int m,n;
    void dfs(vector<vector<char>> &board,int a,int b)
    {
        int dx[4] = {1,-1,0,0},dy[4] = {0,0,1,-1};
        st[a][b] = true;
        for(int i=0;i<4;i++)
        {
            int x = dx[i]+a,y = dy[i]+b;
            if(x>=0&&x<m&&y>=0&&y<n&&board[x][y]=='O'&&!st[x][y])
                dfs(board,x,y);
        }
    }
    void solve(vector<vector<char>>& board) {
        if(!board.size()) return;
        m = board.size(),n = board[0].size();
        st = vector<vector<bool>>(m,vector<bool>(n,false));
        for(int i=0;i<m;i++)
        {
            if(board[i][0]=='O') dfs(board,i,0);
            if(board[i][n-1]=='O') dfs(board,i,n-1);
        }
        for(int i=0;i<n;i++)
        {
            if(board[0][i]=='O') dfs(board,0,i);
            if(board[m-1][i]=='O') dfs(board,m-1,i);
        }
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(!st[i][j])
                    board[i][j] = 'X';
    }
};

// @lc code=end

