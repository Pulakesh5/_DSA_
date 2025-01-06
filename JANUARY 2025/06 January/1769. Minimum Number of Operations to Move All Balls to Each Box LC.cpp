class Solution {
public:
    vector<int> minOperations(string boxes) {
        size_t N = boxes.size();
        vector<int> ans(N);
        int sufixSum = 0, totalball = (boxes[N-1]=='1');
        for(int i=N-2; i>=0; i--)
        {
            ans[N-1] += (boxes[i]=='1' ? (N-1-i) : 0);
            totalball += (boxes[i]=='1');
        }

        sufixSum = (boxes[N-1]=='1');
        for(int i=N-2; i>=0; i--)
        {
            ans[i] = ans[i+1];
            ans[i] += (2*sufixSum - totalball);
            sufixSum += (boxes[i]=='1');
        }
        return ans;
    }
};
