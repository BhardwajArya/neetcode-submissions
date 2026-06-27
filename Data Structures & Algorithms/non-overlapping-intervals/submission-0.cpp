class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int count =0; 
        vector<vector<int>>res={intervals[0]};

        for(int i =1; i<intervals.size(); i++){
            if(intervals[i][0]<res.back()[1]){
                count++;
                res.back()[1]= min(res.back()[1], intervals[i][1]);
            }
            else{
                res.push_back(intervals[i]);
            }
        }
        return count;
    }
};
