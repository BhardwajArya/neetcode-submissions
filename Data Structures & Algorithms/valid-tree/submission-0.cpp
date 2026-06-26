class Solution {
public:
    bool dfs(int node, int parent, vector<vector<int>>&adj, vector<bool>&visited){
        visited[node]= true;
        for(auto a : adj[node]){
            if(a==parent)continue;
            if(visited[a])return false;
            if(!dfs(a, node, adj, visited))return false;
        }
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        vector<bool>visited(n, false);
        for(auto e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        if(!dfs(0, -1, adj, visited))return false;
        for(int i =0; i<n; i++){
            if(!visited[i])return false;
        }
        return true;
    }
};
