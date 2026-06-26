class TimeMap {
    unordered_map<string, vector<pair<int, string>>>store;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto it = store[key];
        sort(it.begin(), it.end());
        int l =0;
        int r = it.size()-1;
        string ans = "";
        while(l<=r){
            int m = l+(r-l)/2;
            if(it[m].first==timestamp){
                return it[m].second;
            }
            if(it[m].first<timestamp){
                l=m+1;
                ans = it[m].second;
            }
            else{
                r=m-1;
            }
        }
        return ans;
    }
};
