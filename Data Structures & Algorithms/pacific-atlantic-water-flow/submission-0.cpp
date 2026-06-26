class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
       queue<pair<int, int>>pac, atl;
       int dirs [4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
       int rows = heights.size();
       int cols= heights[0].size();
       vector<vector<bool>>pacific(rows, vector<bool>(cols, false));
       vector<vector<bool>>atlantic(rows, vector<bool>(cols, false));
       for(int c=0; c<cols; c++){
            pac.push({0, c});
            atl.push({rows-1, c});
            pacific[0][c]=true;
            atlantic[rows-1][c]=true;
       }
       for(int r =0; r<rows; r++){
        pac.push({r, 0});
        atl.push({r, cols-1});
        pacific[r][0]=true;
        atlantic[r][cols-1]=true;
       }


       while(!pac.empty()){
            auto [r, c] = pac.front();
            pac.pop();

            for(auto &d: dirs){
                int nr = r+d[0]; 
                int nc = c+d[1];
                if(nr<0||nr>=rows)continue;
                if(nc<0||nc>=cols)continue;
                if(pacific[nr][nc]==true)continue;
                if(heights[nr][nc]<heights[r][c])continue;
                pacific[nr][nc]= true;
                pac.push({nr, nc});

            }
       }
       while(!atl.empty()){
            auto [r, c] = atl.front();
            atl.pop();

            for(auto &d: dirs){
                int nr = r+d[0]; 
                int nc = c+d[1];
                if(nr<0||nr>=rows)continue;
                if(nc<0||nc>=cols)continue;
                if(atlantic[nr][nc]==true)continue;
                if(heights[nr][nc]<heights[r][c])continue;
                atlantic[nr][nc]= true;
                atl.push({nr, nc});

            }
       }
       vector<vector<int>>res;
       for(int r=0; r<rows; r++){
        for(int c=0; c<cols; c++){
            if(atlantic[r][c]&&pacific[r][c]){
                res.push_back({r,c});
            }
        }
       }
       return res;
    }
};
