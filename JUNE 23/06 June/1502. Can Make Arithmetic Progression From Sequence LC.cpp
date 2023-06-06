class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int preDiff = arr[1] - arr[0];
        int n = arr.size();
        for(int i=2; i<n; i++)
        {
            if(preDiff!=(arr[i] - arr[i-1]))
                return false;
            preDiff = (arr[i] - arr[i-1]);
        }
        return true;
        // return (arr[1] - arr[0]) == (arr[2] - arr[1]);
    }
};
