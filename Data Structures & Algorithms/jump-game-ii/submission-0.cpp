class Solution {
public:
    int jump(vector<int>& nums) {
        int jump =0; 
        int curend=0;
        int farthest=0;
        for(int i =0; i<nums.size()-1; i++){
            farthest = max(farthest, nums[i]+i);
            if(i==curend){
                jump++;
                curend= farthest;
            }
        }
        return jump;
    }
};
