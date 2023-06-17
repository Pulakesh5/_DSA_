class Solution {
public:
    #define infinity 1e9
    int solve(int i, int j, int &len1, int &len2, int p, vector<vector<int>> &dp, vector<int> &arr1, vector<int> &arr2)
    {
        if(i==len1)
            return 0;
        j = upper_bound(arr2.begin()+j, arr2.end(), p) - arr2.begin();
        if(dp[i][j] != -1)
            return dp[i][j];
        if(j==len2 && arr1[i]<=p) return infinity;
        int take = infinity, notTake = infinity;
        if(j!=len2)
            take = solve(i+1, j+1, len1, len2, arr2[j], dp, arr1, arr2) + 1;
        if(arr1[i]>p)
            notTake = solve(i+1, j, len1, len2, arr1[i], dp, arr1, arr2);
        return dp[i][j] = min(take, notTake);
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        bool isIncreasing = true;
        int len1 = arr1.size(), len2 = arr2.size();
        
        for(int i=1; i<len1 && isIncreasing; i++)
            isIncreasing = (arr1[i]>arr1[i-1]);

        if(isIncreasing) return 0;
        
        vector<vector<int>> dp(len1+5, vector<int>(len2+5,-1));
        
        sort(arr2.begin(), arr2.end());
        
        int answer = solve(0,0,len1, len2, -1, dp, arr1, arr2);
        
        if(answer>len1) return -1;
        
        return answer;
    }
};
