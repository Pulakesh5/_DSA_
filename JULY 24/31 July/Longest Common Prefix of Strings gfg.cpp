class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        // your code here
        string commonPrefix = "";
        char commonChar;
        int len = 0, N = arr.size();
        bool exhausted = false;
        while(++len && !exhausted)
        {
            for(int i=0; i<N && !exhausted; i++)
            {
                if(len>arr[i].size())
                {
                    exhausted = true;
                    break;
                }
                if(i==0)
                    commonChar = arr[i][len-1];
                if(arr[i][len-1]!=commonChar)
                    exhausted = true;
            }
            if(!exhausted)
                commonPrefix.push_back(commonChar);
        }
        
        if(commonPrefix.size()==0)
            return "-1";
            
        return commonPrefix;
    }
};
