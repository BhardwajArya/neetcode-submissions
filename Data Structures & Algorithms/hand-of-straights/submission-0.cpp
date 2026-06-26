class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
       map<int, int>mp;
       for(auto i : hand){
            mp[i]++;
       }
       for(auto &[key, cnt]:mp){
            if(cnt>0){
                int n = cnt;
                for(int j=0; j<groupSize; j++){
                   if(mp[key+j]<n) return false;
                   mp[key+j] -= n;
                }
            }
       }
       return true;
       

    }
};
