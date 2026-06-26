class Solution {
public:
    bool dfs(int n, vector<vector<int>>&adj, vector<int>&state, vector<int>&order){
        if(state[n]==1)return false;
        if(state[n]==2)return true;
        state[n]=1;
        for(int m : adj[n]){
            if(!dfs(m, adj, state, order)){
                return false;
            }
        }
        state[n]=2;
        order.push_back(n);
        return true;
    }


    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>state(numCourses, 0);
        vector<int>order;

        for(auto &p : prerequisites){
            adj[p[1]].push_back(p[0]);
        }

        for(int i =0; i<numCourses; i++){
            if(!dfs(i, adj, state, order)){
                return {};
            }
        }
        reverse(order.begin(), order.end());
        return order;
    }
};
