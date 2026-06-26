class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<bool>dp(s.size()+1, false);//dp denotes if ith index of string can be broken
        dp[0]= true; //empty string
        for(int i=1; i<s.size()+1; i++){
            for(int j =0; j<i; j++){
                if(dp[j]&&dict.count(s.substr(j, i-j))){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[s.size()];

    }
};
