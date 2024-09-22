class Solution {
  public:
    int lps(string str) {
        // Your code goes here
        int N = str.size();
        vector<int> pos(N);
        int j = 0;
        for(int i=1; i<N; i++)
        {
            if(str[i]==str[j])
                pos[i] = ++j;
            else
            {
                while((--j)>=0)
                {
                    j = pos[j];
                    if(str[i] == str[j])
                        break;
                }
                pos[i] = ++j;
            }
            // int j = pos[i-1];
            // while(j>0 && str[j]!=str[i])
            //     j = pos[j];
            // if(str[j]==str[i])
            //     j++;
            // pos[i] = j;
        }
        return pos[N-1];
    }
};
