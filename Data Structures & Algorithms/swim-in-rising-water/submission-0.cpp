class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int dirs [4][2] = {{0,1}, {0, -1}, {1, 0}, {-1, 0}};
        int t=0;
        vector<vector<bool>>visited(grid.size(), vector<bool>(grid[0].size(), false));
        vector<vector<int>>dist(grid.size(), vector<int>(grid.size(), INT_MAX));
        dist[0][0]= grid[0][0];
        priority_queue<tuple<int, int, int>, vector<tuple<int,int,int>>, greater<>> minHeap;
        minHeap.push({grid[0][0], 0, 0});
        while(!minHeap.empty()){
            auto [cost, r, c] = minHeap.top();
            minHeap.pop();
            if(visited[r][c])continue;
            visited[r][c]= true;
            for(auto & d: dirs){
                int nr = r+d[0];
                int nc = c+d[1];
                if(nr<0||nr>=grid.size())continue;
                if(nc<0||nc>=grid[0].size())continue;
                if(visited[nr][nc])continue;
                int newcost = max(grid[nr][nc], cost);
                if(newcost<dist[nr][nc]){
                    dist[nr][nc]= newcost;
                    minHeap.push({dist[nr][nc], nr, nc});
                }
            }
        }
        return dist[grid.size()-1][grid[0].size()-1];
    }
};
