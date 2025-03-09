class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int N = colors.size();
        int countOfAlternatingGroups = 0;
        int left = 0;
        for(int right=0; right<(N+k-1); right++)
        {
            if(right>0 && colors[right%N] == colors[(right-1)%N])
                left = right;
            
            if(right-left+1>=k)
                countOfAlternatingGroups++;
        }

        return countOfAlternatingGroups;
    }
};
