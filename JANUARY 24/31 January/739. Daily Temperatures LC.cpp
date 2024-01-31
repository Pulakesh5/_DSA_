class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        
        stack<int> temps;
        int len = temp.size();
        
        vector<int> warmer(len);
        temps.push(len-1);
        for(int i=len-2; i>-1; i--)
        {
            while(!temps.empty() && temp[temps.top()]<=temp[i])
                temps.pop();
            if(!temps.empty())
                warmer[i] = temps.top() - i;
            temps.push(i);
        }
        return warmer;
    }
};
