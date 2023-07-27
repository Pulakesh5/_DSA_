class Solution {
public:
    long long maxRunTime(int computer, vector<int>& batteries) {
        long long totalCharge = 0ll;
        
        for(int battery:batteries)
            totalCharge+=battery;
        
        long long low = 1ll, high = totalCharge/computer, minute, total = 0ll;

        while(low<high)
        {
            minute = (high+low+1)/2;
            total = 0;
            for(int battery:batteries)
                total+=min(1ll*battery, minute);
            if(minute*computer<=total)
                low = minute;
            else
                high = minute - 1;
        }
        return low;
    }
};
