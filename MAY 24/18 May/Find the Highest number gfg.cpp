class Solution {
public:
    int findPeakElement(vector<int>& a) 
    {
        // Code here.
        return *max_element(a.begin(), a.end());
    }
};
