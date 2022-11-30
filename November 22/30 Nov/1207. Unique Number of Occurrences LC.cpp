class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> occurence(1001,0);
        map<int,int> count;

        for(int num:arr)
        {
            count[num]++;
        }
        for(auto it:count)
        {
            occurence[it.second]++;
        }
        
        for(int i=0;i<=1000;i++)
        {
            if(occurence[i]==0) continue;
            if(occurence[i]>1) return false;
        }

        return true;
    }
};
