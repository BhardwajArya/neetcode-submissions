class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int dirs [4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int rows = grid.size();
        int cols = grid[0].size();
        int fresh=0;
        queue<tuple<int, int, int>>q;
        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                if(grid[r][c]==2){
                    q.push({r,c, 0});
                }
                if(grid[r][c]==1)fresh++;
            }
        }
        int minutes=0;
        while(!q.empty()){
            auto[r, c, time]=q.front();
            q.pop();
            for(auto &d:dirs){
                int nr = r+d[0];
                int nc = c+d[1];
                if(nr>=rows||nr<0)continue;
                if(nc>=cols||nc<0)continue;
                if(grid[nr][nc]!=1)continue;
                fresh--;
                minutes = max(minutes, time+1);
                grid[nr][nc]=2;
                q.push({nr,nc, time+1});
            }
            
        }
        if(fresh==0)return minutes;
        else{
            return -1;
        }
    }
};
