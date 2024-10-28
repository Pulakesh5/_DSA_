class Solution {
  public:
    vector<int> removeDuplicate(vector<int>& arr) {
        // code here
        
        set<int> exists;
        vector<int> noDups;
        for(int num:arr)
        {
            if(exists.find(num)!=exists.end())
                continue;
            noDups.push_back(num);
            exists.insert(num);
        }
        return noDups;
    }
};
