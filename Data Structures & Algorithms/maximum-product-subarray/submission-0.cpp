class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int>maxdp(n, 0);
        vector<int>mindp(n, 0);
        int ans = nums[0];
        maxdp[0]=nums[0];
        mindp[0]=nums[0];
        for(int i=1; i<n; i++){
           maxdp[i]= max({nums[i], maxdp[i-1]*nums[i], mindp[i-1]*nums[i]});
           mindp[i] = min({nums[i], maxdp[i-1]*nums[i], mindp[i-1]*nums[i]});
           ans = max(ans, maxdp[i]);
        }
        return ans;
    }
};
