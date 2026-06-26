class Solution {
    unordered_map<int, int>memo;
    int dp(vector<int>&nums, int n){
        if(n==0)return nums[0];
        if(n==1)return max(nums[0], nums[1]);
        if(memo.count(n))return memo[n];
        memo[n]=max(dp(nums, n-1), dp(nums, n-2)+nums[n]);
        return memo[n];
    }
public:
    int rob(vector<int>& nums) {
        return dp(nums, nums.size()-1);
    }
};
