class Solution {
  public:
    int sameOccurrence(vector<int>& arr, int x, int y) {
        // code here
        int countX = 0, countY = 0;
        map<int, int> mp;
        for(int num:arr) {
            countX += (num==x);
            countY += (num==y);
            mp[countX-countY]++;
        }
        int subarrayCount = mp[0];
        for(auto it:mp)
        {
            subarrayCount += (it.second*(it.second-1))/2;
        }
        return subarrayCount;
    }
};
