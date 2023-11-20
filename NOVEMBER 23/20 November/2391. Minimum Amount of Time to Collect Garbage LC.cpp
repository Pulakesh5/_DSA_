class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        vector<int> totalCount(3,0);
        int n=garbage.size();
        for(int i=0; i<n; i++)
        {
            for(char ch:garbage[i])
                totalCount[0]+=(ch=='M');
        }
        for(int i=0; i<n; i++)
        {
            for(char ch:garbage[i])
                totalCount[1]+=(ch=='P');
        }
        for(int i=0; i<n; i++)
        {
            for(char ch:garbage[i])
                totalCount[2]+=(ch=='G');
        }
        int totalMinutes=0, count=0;
        for(int i=0; i<n; i++)
        {
            count=0;
            for(char ch:garbage[i])
                count+=(ch=='M');
            totalCount[0]-=count;
            totalMinutes+=count;
            if(i!=0)
                totalMinutes+=travel[i-1];
            if(totalCount[0]==0)
                break;
        }
        for(int i=0; i<n; i++)
        {
            count=0;
            for(char ch:garbage[i])
                count+=(ch=='P');
            totalCount[1]-=count;
            totalMinutes+=count;
            if(i!=0)
                totalMinutes+=travel[i-1];
            if(totalCount[1]==0)
                break;
        }
        for(int i=0; i<n; i++)
        {
            count=0;
            for(char ch:garbage[i])
                count+=(ch=='G');
            totalCount[2]-=count;
            totalMinutes+=count;
            if(i!=0)
                totalMinutes+=travel[i-1];
            if(totalCount[2]==0)
                break;
        }
        return totalMinutes;
    }
};
