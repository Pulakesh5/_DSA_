class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int len = tickets.size();
        int time = 0;
        for(int i=0; i<=k; i++)
            time+=min(tickets[i],tickets[k]);
        for(int i=k+1; i<len; i++)
            time+=min(tickets[i], tickets[k]-1);
        return time;
    }
};
