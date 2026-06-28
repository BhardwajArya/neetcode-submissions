class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>>adj(n+1);
        for(auto t: times){
            adj[t[0]].push_back({t[1], t[2]});
        }
        vector<int>dist(n+1, INT_MAX);
        dist[k]=0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>minheap;
        minheap.push({0, k});
        vector<bool>visited(n+1, false);
        while(!minheap.empty()){
            auto [cost, node] =  minheap.top();
            minheap.pop();
            if(visited[node])continue;
            visited[node]= true;
            for(auto t: adj[node]){
                if(cost+ t.second<dist[t.first]){
                    dist[t.first]=cost+t.second;
                    minheap.push({dist[t.first], t.first});
                }
            }

        }
        int ans = *max_element(dist.begin()+1, dist.end());
        return ans == INT_MAX ? -1 : ans;
    }
};
