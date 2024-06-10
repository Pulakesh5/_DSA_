class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> expected(heights.begin(), heights.end());
        sort(expected.begin(), expected.end());
        int count=0, len = heights.size();
        for(int i=0; i<len; i++)
        {
            if(heights[i]!=expected[i])
                count++;
        }
        return count;
    }
};
