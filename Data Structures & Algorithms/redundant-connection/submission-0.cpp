class Solution {

public:
    int find(int x, vector<int>&parent){
        if(parent[x]!=x){
            parent[x]= find(parent[x], parent);
        }
        return parent[x];
    }
    bool unite(int x, int y, vector<int>&parent){
        int px= find(x, parent);
        int py= find(y, parent);
        if(px==py)return false;
        parent[px]=py;
        return true;
        
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int>parent(n+1);
        iota(parent.begin(), parent.end(), 0);
        //stack<vector<int>>st;
        for(auto a: edges){
            if(!unite(a[0], a[1], parent))return a;
        }
        return {};
    }
};
