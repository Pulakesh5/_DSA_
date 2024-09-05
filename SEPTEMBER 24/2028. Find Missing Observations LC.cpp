class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        long long total = 1ll*(n+m)*mean;
        
        for(int roll:rolls)
            total-=roll;
        if(total>6*n || total<n)
            return {};
        vector<int> missing_rolls(n, (total/n));
        total -= (n*(total/n));
        for(int i=0; i<n && total; i++)
        {
            missing_rolls[i] +=1;
            total--;
        }
        return missing_rolls;
    }
};
