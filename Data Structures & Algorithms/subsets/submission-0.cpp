class Solution {
    vector<int>curr;
    vector<vector<int>>res;
    void backtrack(vector<int>&nums, int idx){
        if(idx==nums.size()){
            res.push_back(curr);
            return;
        }
        backtrack(nums, idx+1);
        curr.push_back(nums[idx]);
        backtrack(nums, idx+1);
        curr.pop_back();

    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(nums,0);
        return res;
    }
};
