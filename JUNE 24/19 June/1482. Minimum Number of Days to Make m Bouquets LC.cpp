class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long n = bloomDay.size();
        if(1ll*m*k>n)
            return -1;
        int left = 1, right = 1e9;
        int flow, bouqet, minDay;
        while(left<right)
        {
            minDay = (left+right)/2;
            flow = 0;
            bouqet = 0;

            for(int i=0; i<n; i++)
            {
                if(bloomDay[i]>minDay)
                {
                    flow = 0;
                } else if(++flow>=k) {
                    bouqet++;
                    flow = 0;
                }
            }
            if(bouqet<m)
                left = minDay+1;
            else
                right= minDay;
        }
        return left;

        
    }
};
