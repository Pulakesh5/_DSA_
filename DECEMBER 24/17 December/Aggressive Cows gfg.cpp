class Solution {
  public:

    int aggressiveCows(vector<int> &stalls, int k) {

        // Write your code here
        sort(stalls.begin(), stalls.end());
        int low=0, high = *max_element(stalls.begin(), stalls.end()) - *min_element(stalls.begin(), stalls.end());
        int N = stalls.size(), diff, maxDiff = 0;
        while(low<=high)
        {
            diff = (low+high)/2;
            int cows=k;
            int index = 0;
            while(index<N && --cows)
            {
                index = lower_bound(stalls.begin(), stalls.end(), (stalls[index]+diff)) - stalls.begin();
            }
            // cout<<diff<<" : "<<index<<" "<<cows<<endl;
            if(cows==0)
            {
                maxDiff = max(maxDiff, diff);
                low = diff+1;
            }
            else
                high = diff-1;
        }
        return maxDiff;
    }
};
