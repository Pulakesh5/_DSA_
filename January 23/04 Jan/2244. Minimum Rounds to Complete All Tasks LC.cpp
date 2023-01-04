class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int,int> count;
        for(int task:tasks)
            count[task]++;
        int round=0;
        for(auto it:count)
        {
            if(it.second<=1)
                return -1;
            round+=((it.second+2)/3);
        }
        return round;
    }
};
