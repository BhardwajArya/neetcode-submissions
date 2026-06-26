class Solution {
    vector<string>v;
    void backtrack(string s, int open, int close, int n){
        if(s.size()==2*n){
            v.push_back(s);
            return;
        }
        if(open<n){
            backtrack(s+'(', open+1, close, n);

        }
        if(close<open){
            backtrack(s+')', open, close+1, n);
        }
        
        
    }
public:
    vector<string> generateParenthesis(int n) {
        string s ="";
        backtrack(s, 0, 0, n);
        return v;
    }
};
