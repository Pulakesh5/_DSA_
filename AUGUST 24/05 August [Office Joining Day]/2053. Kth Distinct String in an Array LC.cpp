class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> freq;
        for(string it:arr)
            freq[it]++;
        for(string it:arr)
        {
            if(freq[it]==1 && --k==0)
                return it;
        }
        return "";
    }
};
