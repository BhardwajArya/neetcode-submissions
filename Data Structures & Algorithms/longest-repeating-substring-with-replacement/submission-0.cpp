class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int>st;
        int l =0;
        int maxf=0;
        int res=0;
        for(int r =0; r<s.size(); r++){
            st[s[r]]++;
            maxf = max(maxf, st[s[r]]);
            while((r-l+1)-maxf > k){
                st[s[l]]--;
                l++;
            }
            res= max(res, r-l+1);
        }
        return res;
    }
};
