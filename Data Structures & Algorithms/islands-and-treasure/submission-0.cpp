class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int INF = 2147483647;
        int dirs[4][2]={{0, 1}, {0, -1}, {1, 0}, {-1,0}};
        queue<pair<int, int>>q;
        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                if(grid[r][c]==0){
                    q.push({r,c});
                }
            }
        }
        while(!q.empty()){
            auto [r, c]= q.front();
            q.pop();
            for(auto &d:dirs){
                int nr = r+d[0];
                int nc = c+d[1];
                if(nr<0||nr>=rows)continue;
                if(nc<0||nc>=cols)continue;
                if(grid[nr][nc]!=INF)continue;
                grid[nr][nc]= grid[r][c]+1;
                q.push({nr, nc});
            }
        }
    }
};
