class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq;
        int n=heights.size();
        int diff, i=1, lastPosition=0, sum=0;
        while(i<n && sum<=bricks)
        {
            diff = (heights[i]-heights[i-1]);
            if(diff>0)
            {
                sum+=diff;
                pq.push(diff);
                while(sum>bricks && ladders)
                {
                    ladders--;
                    sum-=pq.top();
                    pq.pop();
                }
                if(sum>bricks)
                    break;
            }
            i++;
            lastPosition++;
        }
        return lastPosition;
    }
};
