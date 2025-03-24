class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int lastMeetingEnd = -1, lastMeetingStart=-1;
        int N = meetings.size();
        int countAvailableDays = days;
        for(int i=0; i<N; i++)
        {
            if(lastMeetingEnd < meetings[i][0])
            {
                if(lastMeetingEnd!=-1)
                    countAvailableDays -= (lastMeetingEnd-lastMeetingStart+1);
                lastMeetingStart = meetings[i][0];
                lastMeetingEnd = meetings[i][1];
            }
            else 
                lastMeetingEnd = max(lastMeetingEnd, meetings[i][1]);
        }
        countAvailableDays -= (lastMeetingEnd-lastMeetingStart+1);
        return countAvailableDays;
    }
};
