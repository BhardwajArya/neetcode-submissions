class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<bool>visited(n, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>minHeap;
        minHeap.push({0, 0});
        int totalcost=0;
        while(!minHeap.empty()){
            auto [cost, point] = minHeap.top();
            minHeap.pop();
            if(visited[point])continue;
            visited[point]= true;
            totalcost+=cost;
            for(int i =0; i<n; i++){
                if(!visited[i]){
                    int dist = abs(points[i][0]-points[point][0])+abs(points[i][1]-points[point][1]);
                    minHeap.push({dist, i});
                }
            }

        }
        return totalcost;
    
    }
};
