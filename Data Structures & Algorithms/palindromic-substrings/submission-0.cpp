class Solution {
    int res=0;
    void expand(string &s, int l, int r){
        while(l>=0 && r<s.size() && s[l]==s[r]){
            res++;
            l--;
            r++;
        }
        

    }
public:
    int countSubstrings(string s) {
        //int res=0;
        for(int i =0; i<s.size(); i++){
            expand(s, i, i);
            expand(s, i, i+1);
        }
        return res;
    }
};
