class Solution {
  public:

    bool checkDuplicatesWithinK(vector<int>& arr, int k) {
        map<int, int> mp;
        
        for(int i = 0 ; i < arr.size() ; i++) {
            if (mp.find(arr[i]) == mp.end())
                mp[arr[i]] = i;
                
            else {
                if(i - mp[arr[i]] <= k)
                    return true;
                else
                    mp[arr[i]] = i;
            }
        }
        
        return false;
    }
};
