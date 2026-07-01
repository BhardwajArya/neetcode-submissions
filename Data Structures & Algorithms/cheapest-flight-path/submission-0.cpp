class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int m = 1;
        vector<int>dist(n, INT_MAX);
        dist[src]=0;
        while(m<=k+1){
            m++;
            auto temp = dist;
            for(auto &d : flights){
                if(dist[d[0]]!=INT_MAX){
                    temp[d[1]]= min(temp[d[1]], dist[d[0]]+d[2]);
                }
            }
            dist= temp;
        } 
        return dist[dst] == INT_MAX?-1:dist[dst];
    }
};
