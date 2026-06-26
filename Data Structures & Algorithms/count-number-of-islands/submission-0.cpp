class Solution {
    int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    //int no=0;
    void dfs(int r, int c, vector<vector<char>>&grid, vector<vector<bool>>&visited){
        visited[r][c]=true;
        for(auto d:dirs){
            int nr = r + d[0];
            int nc = c + d[1];
            
            if(nr>=grid.size()||nr<0)continue;
            if(nc>=grid[0].size()||nc<0)continue;
            if(visited[nr][nc]==true)continue;
            if (grid[nr][nc] == '0') continue;

            dfs(nr, nc, grid, visited);

        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>>visited(grid.size(),  vector<bool>(grid[0].size(), false));
        int count=0;
        for(int r=0; r<grid.size(); r++){
            for(int c=0; c<grid[0].size(); c++){
                if(!visited[r][c]&&grid[r][c]!='0'){
                    count++;
                    dfs(r, c, grid, visited);
                }
            }
        }
        return count;
    }
};
