class Solution {
  public:

    string pattern(vector<vector<int>> &arr) {
        // Code Here
        int R = arr.size(), C=arr[0].size();
        for(int i=0; i<R; i++)
        {
            bool palindrome1 = true, palindrome2 = true;
            for(int l=0, r=C-1; l<r; l++, r--)
            {
                if(arr[i][l]!=arr[i][r])
                {
                    palindrome1 = false;
                }
            }
            
            if(palindrome1)
            {
                string ans = "";
                ans += to_string(i);
                ans +=" R";
                return ans;
            }
        }
        
        for(int i=0; i<C; i++)
        {
            bool palindrome1 = true, palindrome2 = true;
            for(int l=0, r=R-1; l<r; l++, r--)
            {
                if(arr[l][i]!=arr[r][i])
                {
                    palindrome2 = false;
                }
            }
            
            if(palindrome2)
            {
                string ans = "";
                ans += to_string(i);
                ans +=" C";
                return ans;
            }
        }
        
        return "-1";
    }
};
