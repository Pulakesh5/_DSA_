class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n=heights.size();
        priority_queue<int> pq;
        int i=1,position=0;
        int sum=0,diff;
        while(i<n && sum<=bricks){
            diff=(heights[i]-heights[i-1]);
            if(diff>0){
                sum+=diff;
                pq.push(diff);
                while(sum>bricks && ladders){
                    int frnt=pq.top();
                    sum-=frnt;
                    pq.pop();
                    ladders--;
                }
                if(sum>bricks)
                    break;
            }
            i++;
            position++;
        }
        return position;
        
    }
};
