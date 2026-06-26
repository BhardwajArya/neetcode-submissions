class Solution {
    vector<vector<string>>res;
    vector<string>cur;
    bool isPalindrome(string word){
        int l =0;
        int r= word.size()-1;
        while(l<=r){
            if(word[l]!=word[r])return false;
            l++;
            r--;
        }
        return true;
    }
    void backtrack(string word, int idx){
        if(idx==word.size()){
            res.push_back(cur);
            return;
        }
        for(int end=idx; end<word.size(); end++){
            string piece = word.substr(idx, end-idx+1);
            if(isPalindrome(piece)){
            cur.push_back(piece);
            backtrack(word, end+1);
            cur.pop_back();
            }
        }

    }
    
public:
    vector<vector<string>> partition(string s) {
        backtrack(s, 0);
        return res;
    }
};
