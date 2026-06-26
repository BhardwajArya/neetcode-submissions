class Solution {
public:
    bool dfs(int n, vector<vector<int>>&adj, vector<int>&state){
        if(state[n]==1){
            return false;
        }
        if(state[n]==2){
            return true;
        }
        state[n]= 1;
        for(int m : adj[n]){
            if(!dfs(m, adj, state)){
                return false;
            }
        }
        state[n]=2;
        return true;
    }


    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>state(numCourses, 0);
        for(auto &p : prerequisites){
            adj[p[1]].push_back(p[0]);
        }
        for(int i =0; i<numCourses; i++){
            if(!dfs(i, adj, state)){
                return false;
            }
        }
        return true;
    }
};
