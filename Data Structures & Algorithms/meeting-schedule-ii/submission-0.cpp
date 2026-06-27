/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){
            return a.start<b.start;
        });
        priority_queue<int, vector<int>, greater<int>>p;
        for(int i =0; i<intervals.size(); i++){
            if(!p.empty()&&p.top()<=intervals[i].start){
                p.pop();
            }
            p.push(intervals[i].end);
        }
        return p.size();
    }
};
