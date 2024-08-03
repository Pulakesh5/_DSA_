class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        vector<int> freq(1001,0);
        int N = target.size();
        for(int i=0; i<N; i++)
            freq[target[i]]++;
        N = arr.size();
        for(int i=0; i<N; i++)
            freq[arr[i]]--;
        for(int i=1; i<=1000; i++)
        {
            if(freq[i])
                return false;
        }
        return true;
    }
};
