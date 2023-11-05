class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        if(k>=arr.size())
            return *max_element(arr.begin(), arr.end());
        int current = arr[0], win = 0, len = arr.size();
        for(int i=1; i<len; i++)
        {
            if(arr[i]>current)
            {
                current = arr[i];
                win = 0;
            }
            if(++win == k)
                break;
        }
        return current;
    }
};
