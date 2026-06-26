class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int>st;
        int result=0;
        for(auto i : nums){
            st[i]++;
            if(st[i]>1){
               result = i;
            }
        }
        return result;
    }
};
