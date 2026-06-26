class Solution {
public:
    void dfs(int n, vector<vector<int>>&adj, vector<bool>&visited){
        visited[n]=true;
        for(auto e:adj[n]){
            if(visited[e])continue;
            dfs(e, adj, visited);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        vector<bool>visited(n, false);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int count=0;
        for(int i =0; i<n; i++){
            if(!visited[i]){
                dfs(i, adj, visited);
                count++;
            
            }
        }
        return count;
    }
};
