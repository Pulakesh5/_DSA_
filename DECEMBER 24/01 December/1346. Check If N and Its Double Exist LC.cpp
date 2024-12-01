class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int N = arr.size();
        for(int i=0; i<(N-1); i++)
        {
            for(int j=i+1; j<N; j++)
            {
                if(arr[j] == 2*arr[i] || arr[i]==2*arr[j])
                    return true;
            }
        }
        return false;
    }
};
