class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(int n, int start[], int end[]) {
        // Your code here
        vector<vector<int>> vp(n);
        for(int i=0; i<n; i++)
            vp[i] = {end[i], start[i]};
            
        sort(vp.begin(), vp.end());
        
        int prevEnd = -1;
        int meetings = 0;
        
        for(int i=0; i<n; i++)
        {
            if(vp[i][1]>prevEnd)
            {
                meetings++;
                prevEnd = vp[i][0];
            }
        }
        
        return meetings;
    }
};
