class Solution {
    int dirs [4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    void dfs(int r, int c, vector<vector<char>>&grid, vector<vector<bool>>&safe){
        safe[r][c]= true;
        for(auto &d: dirs){
            int nr = r+d[0];
            int nc = c+ d[1];
            if(nr>=grid.size()||nr<0)continue;
            if(nc>=grid[0].size()||nc<0)continue;
            if(safe[nr][nc])continue;
            if(grid[nr][nc]=='X')continue;
            safe[nr][nc]= true;
            dfs(nr, nc, grid, safe);
        }

    }
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<bool>>safe(rows, vector<bool>(cols, false));
        for(int r=0; r<rows; r++){
            if(board[r][0]=='O'){
                dfs(r, 0, board, safe);
            }
            if(board[r][cols-1]=='O'){
                dfs(r, cols-1, board, safe);
            }
        }
        for(int c=0; c<cols; c++){
            if(board[0][c]=='O'){
                dfs(0, c, board, safe);
            }
            if(board[rows-1][c]=='O'){
                dfs(rows-1, c, board, safe);
            }
        }
        for(int r =0; r<rows; r++){
            for(int c=0; c<cols; c++){
                if(!safe[r][c]){
                    board[r][c]='X';
                }
            }
        }
    }
};
