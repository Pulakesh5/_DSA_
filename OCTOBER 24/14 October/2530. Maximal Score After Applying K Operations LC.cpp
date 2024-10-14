class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        int top;
        long long score = 0;
        while(k--) {
            top = pq.top();
            score += top;
            pq.pop();
            if(top == 1){
                score += k;
                break;
            }
            pq.push((top+2)/3);
        }
        return score;
    }
};
