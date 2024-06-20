class Solution {
private:

public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n = position.size();
        long long left=0, right=(position[n-1]-position[0]);
        long long dist, curr, count;
        
        while(left<right)
        {
            dist = right - (right-left)/2;
            curr = position[0];
            count = 1;
            for(int i=1; i<n; i++)
            {
                if(position[i]-curr>=dist)
                {
                    count++;
                    curr = position[i];
                }
            }
            if(count>=m)
                left = dist;
            else
                right = dist-1;
        }
        return left;
    }
};
