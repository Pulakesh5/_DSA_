class Solution {
public:
    bool isNStraightHand(vector<int>& hands, int groupSize) {
        if(groupSize==1)
            return true;
        
        if(hands.size()%groupSize!=0)
            return false;
        
        map<int,int> count;
        
        for(int hand:hands)
            count[hand]++;
        int prev, groupCount=(hands.size()/groupSize), next;
        for(int group=1; group<=groupCount; group++)
        {
            prev=(*count.begin()).first;
            count[prev]--;
            if(count[prev]==0)
                    count.erase(count.find(prev));

            for(int i=1; i<groupSize; i++)
            {
                next = prev+1;
                if(count.find(next)==count.end())
                {
                    return false;
                }
                count[next]--;
                if(count[next]==0)
                    count.erase(count.find(next));
                prev = next;
            }
        }
        return true;
    }
};
