class Solution {
  public:
    // Function to determine if array arr can be split into three equal sum sets.
    vector<int> findSplit(vector<int>& arr) {
        // code here
        map<int, int> sumExists;
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        int currSum = 0;
        size_t len = arr.size();
        for(size_t i=0; i<len; i++)
        {
            currSum += arr[i];
            if(currSum%2==0 && sumExists.find(currSum/2)!=sumExists.end())
            {
                if(totalSum-currSum == (currSum/2))
                    return{sumExists[currSum/2], i};
            }
            sumExists[currSum] = i;
        }
        return {-1, -1};
    }
};
