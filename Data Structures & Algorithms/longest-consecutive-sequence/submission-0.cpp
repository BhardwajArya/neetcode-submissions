class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(int i=0; i<nums.size(); i++){
            st.insert(nums[i]);
        }
        int longest=0;
        int length=0;
        for(int i=0; i<nums.size(); i++){
            if(st.find(nums[i]-1)==st.end()){
                length =1;
                while(st.find(nums[i]+length)!=st.end()){
                    length++;
                }
                longest = max(length, longest);
            }
                
            
        }
        return longest;
    }
};
