class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>q;
        for(int i: stones){
            q.push(i);
        }
        while(q.size()>1){
            int y = q.top();
            q.pop();
            int x = q.top();
            q.pop();
            //if(x==y){continue;}
            if(x<y){
                y=y-x;
                q.push(y);
            }
        }
        if(q.size()==0)return 0;
        else{
            return q.top();
        }
    }
};
