class Solution {
    
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>, vector<pair<int,vector<int>>>, greater<pair<int,vector<int>>>>q;
        int n = points.size();
        int i=0;
        while(i<n){
            auto v = points[i];
            int x = v[0];
            int y = v[1];
            int dist = (x*x+y*y);
            q.push({dist, v});
            i++;
        }
        vector<vector<int>>res;
        for(int j =0; j<k; j++){
            auto it = q.top();
            q.pop();
            res.push_back(it.second);
        }
        return res;
        
    }
};
