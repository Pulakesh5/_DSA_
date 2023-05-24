class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int len = nums1.size();
        vector<pair<int,int>> vp(len);

        for(int i=0; i<len; i++)
            vp[i] = {nums2[i], nums1[i]};
        
        sort(vp.begin(), vp.end());

        long long currSum = 0;
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i=len-1; i>=(len-k); i--)
        {
            currSum+=vp[i].second;
            pq.push(vp[i].second);
        }
        long long ans = currSum * vp[len-k].first;
        for(int i=len-1-k; i>=0; i--)
        {          
            currSum-=pq.top();
            pq.pop();

            currSum+=vp[i].second;
            pq.push(vp[i].second);
            ans = max(ans, currSum*vp[i].first);
        }
        return ans;
    }
};
