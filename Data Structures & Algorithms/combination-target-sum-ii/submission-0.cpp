class Solution {
    vector<vector<int>>res;
    vector<int>cur;
    void backtrack(vector<int>&candidates, int target, int idx){
        if(target==0){
            res.push_back(cur);
            return;
        }
        if(target<0)return;
        for(int i = idx; i<candidates.size(); i++){
            if(i>idx && candidates[i]==candidates[i-1])continue;
            cur.push_back(candidates[i]);
            backtrack(candidates, target-candidates[i], i+1);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0);
        return res;
    }
};
