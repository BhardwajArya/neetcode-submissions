class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>count;
        for(int i=0; i<nums.size(); i++){
            count[nums[i]]++;
        }
        vector<pair<int, int>>temp;
        for(auto p: count){
            temp.push_back({p.second, p.first});
        }
        sort(temp.rbegin(), temp.rend());
        vector<int>res;
        for(int i=0; i<k; i++){
            res.push_back(temp[i].second);
        }
        return res;
        
    }
};
