class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int len = pref.size();
        vector<int> arr(len);
        arr[0] = pref[0];
        for(int i=1; i<len; i++)
            arr[i] = pref[i]^pref[i-1];
        return arr;
    }
};
