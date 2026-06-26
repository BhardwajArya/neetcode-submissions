class Solution {
    vector<vector<int>>res;
    vector<int>cur;
    void backtrack(vector<int>&nums, int target, int idx){
        if(target==0){
            res.push_back(cur);
            return;
        }
        if(target<0)return;
        for(int i = idx; i<nums.size(); i++){
            cur.push_back(nums[i]);
            backtrack(nums, target-nums[i], i);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        backtrack(nums, target, 0);
        return res;
    }
};
