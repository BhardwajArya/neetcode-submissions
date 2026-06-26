class Solution {
    unordered_map<int, int>memo;
    int dp(vector<int>&nums, int start, int end){
        if(start==end)return nums[start];
        if(start+1==end)return max(nums[start], nums[end]);
        if(memo.count(end))return memo[end];
        memo[end]= max(dp(nums, start, end-1), dp(nums, start, end-2)+nums[end]);
        return memo[end];
    }
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
         memo.clear();
        int n = dp(nums,1, nums.size()-1);
        memo.clear();
        int m = dp(nums,0, nums.size()-2);
        //memo.clear();
        return max(m, n);
    }
};
