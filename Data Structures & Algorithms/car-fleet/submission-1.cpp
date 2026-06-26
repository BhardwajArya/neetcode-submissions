class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>>pt;
        for(int i=0; i<position.size(); i++){
            pt.push_back({position[i], speed[i]});
        }
        sort(pt.rbegin(), pt.rend());
        vector<double>stack;
        for(int i =0; i<position.size(); i++){
            double tt = (double)(target-pt[i].first)/pt[i].second;
            stack.push_back(tt);
            if(stack.size()>=2 && stack.back()<=stack[stack.size()-2]){
                stack.pop_back();
            }
        }
        return stack.size();
    }
};
