class Solution {
    int dir [4][2]={{0, 1}, {0, -1}, {1, 0}, {-1,0}};

    int dfs(int r, int c, vector<vector<int>>&grid, vector<vector<bool>>&visited){
        visited[r][c]=true;
        int count =1;
        for(auto d:dir){
            int nr = r+d[0];
            int nc = c +d[1];
            if(nr>=grid.size()||nr<0)continue;
            if(nc>=grid[0].size()||nc<0)continue;
            if(visited[nr][nc])continue;
            if(grid[nr][nc]!=1)continue;
            count+=dfs(nr, nc, grid, visited);
        }
        return count;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols= grid[0].size();
        vector<vector<bool>>visited(rows, vector<bool>(cols, false));
        int res=0;
        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                if(!visited[r][c]&&grid[r][c]==1){
                    int count = dfs(r, c, grid, visited);
                    res= max(count, res);
                }
            }
        }
        return res;
    }
};
