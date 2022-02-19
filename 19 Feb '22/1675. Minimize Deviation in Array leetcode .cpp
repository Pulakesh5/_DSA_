/*
odd*2 = even odds can be used once
even/2 = even or odd


*/

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int res = INT_MAX , mn = INT_MAX;
        priority_queue<int> pq;
        
        for(auto num:nums){
            if(num%2) num*=2;
            pq.push(num);
            mn=min(mn,num);
        }
        
        while(pq.top()%2==0){
            res = min(res, pq.top()-mn);
            mn=min(mn, pq.top()/2);
            pq.push(pq.top()/2);
            pq.pop();
        }
        return res=min(res, pq.top()-mn);
    }
};
