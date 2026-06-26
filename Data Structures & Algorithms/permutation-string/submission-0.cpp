class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int>st;
        for(char s: s1){
            st[s]++;
        }
        unordered_map<char, int>tt;
        int r=0; int l=0;
        while(r<s2.size()){
            if((r-l+1)>s1.size()){
                tt[s2[l]]--;
                if(tt[s2[l]]==0)tt.erase(s2[l]);
                l++;
            }
            tt[s2[r]]++;
            r++;
            if(tt==st)return true;
            
        }
        return false;
    }
};
