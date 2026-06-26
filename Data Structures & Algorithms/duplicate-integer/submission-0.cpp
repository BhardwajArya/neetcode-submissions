class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> st;
        for(auto i: nums){
            st[i]++;
            if(st[i]>1) return true;
        }
        return false;
    }
};