class Solution {
  public:
    long long findSmallest(vector<int> &arr) {
        // Your code goes here.
        long long notPossible = 1;
        sort(arr.begin(), arr.end());
        for(int num:arr) 
        {
            if(num>notPossible)
                return notPossible;
            notPossible+=num;
        }
        return notPossible;
    }
};
