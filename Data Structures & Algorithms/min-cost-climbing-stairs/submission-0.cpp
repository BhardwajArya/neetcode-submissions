class Solution {
    unordered_map<int, int>memo;//store min cost to reach that node
    int dp(vector<int>&cost, int n){
        if(n==0||n==1)return 0;
        if(memo.count(n))return memo[n];
        
        memo[n] = min(dp(cost, n-1)+cost[n-1], dp(cost, n-2)+cost[n-2]);
        return memo[n];
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = dp(cost, cost.size());
        return n;
    }
};
