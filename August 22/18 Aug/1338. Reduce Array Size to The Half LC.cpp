class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int,int> mp;
        int n=arr.size();
        for(int i=0;i<n;i++)
            mp[arr[i]]++;
        priority_queue<int> pq;
        for(auto it:mp)
            pq.push(it.second);
        int removed=0,count=0;
        
        while(!pq.empty() && removed<(n/2)){
            removed+=pq.top();
            count++;
            pq.pop();
        }
        return count;
    }
};
