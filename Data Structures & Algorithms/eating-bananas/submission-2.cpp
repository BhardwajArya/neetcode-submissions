class Solution {
public:
    int timetaken(vector<int>piles, int k){
        long long  h = 0;
        for(int i : piles){    
            h += (i+k-1)/k;
        }
        return h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int res=INT_MAX;
        sort(piles.begin(), piles.end());
        int l =1; 
        int r =*max_element(piles.begin(), piles.end());

        while(l<=r){
            int mid = l+((r-l)/2);
            if(timetaken(piles, mid)>h){
                l=mid+1;
            }
            else{
                res = mid;
                r = mid-1;
            }
        }
        return res;
    }
};
