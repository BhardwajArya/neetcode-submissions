class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int>holding(n);
        vector<int>free(n, 0);
        vector<int>cooldown(n, 0);
        holding[0]= - prices[0];
        for(int i =1; i<n; i++){
            holding[i]= max(holding[i-1], free[i-1]-prices[i]);
            free[i] = max(free[i-1], cooldown[i-1]);
            cooldown[i]= holding[i-1]+prices[i];
        }
        return max(cooldown[n-1], free[n-1]);
    }
};
