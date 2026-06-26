class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxsum=nums[0];
        for(int i =0; i<nums.size(); i++){
            if(maxsum>=i){
                maxsum=max(maxsum, i+nums[i]);
            }
        }
        if(maxsum>=nums.size()-1)return true;
        else{
            return false;
        }
    }
};
