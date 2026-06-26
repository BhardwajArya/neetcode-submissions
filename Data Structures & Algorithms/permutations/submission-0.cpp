class Solution {
    vector<vector<int>>res;
    vector<int>cur;
    vector<bool>used;
    void backtrack(vector<int>&nums){
        if(cur.size()==nums.size()){
            res.push_back(cur);
            return;
        }
        for(int i =0; i<nums.size(); i++){
            if(used[i])continue;
            used[i]=true;
            cur.push_back(nums[i]);
            backtrack(nums);
            cur.pop_back();
            used[i]= false;
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        used.resize(nums.size(), false);
        backtrack(nums);
        return res;
    }
};
