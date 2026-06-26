class KthLargest {
    priority_queue<int>pq;
    int max = 0;
public:
    KthLargest(int k, vector<int>& nums) {
        max=k;
        for(int i:nums){
            pq.push(i);
        }
    }
    
    int add(int val) {
        pq.push(val);
        priority_queue<int>q(pq);
        int n =1;
        while(n<max){
            q.pop();
            n++;
        }
        return q.top();
    }
};
