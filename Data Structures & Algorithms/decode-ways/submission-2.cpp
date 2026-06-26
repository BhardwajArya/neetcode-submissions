class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int>dp(n, 0);
        dp[0]=s[0]!='0'?1:0;
        for(int i=1; i<n; i++){
            if(s[i]!='0'){
                dp[i]+=dp[i-1];
            }
            int two = stoi(s.substr(i-1, 2));
            if(two>=10&&two<=26){
                dp[i]+= i>=2?dp[i-2]:1;
            }
            
        }
        return dp[n-1];
    }
};
