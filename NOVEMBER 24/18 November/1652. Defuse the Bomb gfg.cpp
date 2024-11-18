class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        if(k==0)
            return vector<int>(code.size());
        size_t len = code.size();
        vector<int> ans(len);
        if(k>0)
        {
            for(int i=0; i<len; i++)
            {
                for(int j=1; j<=k; j++)
                {
                    ans[i] += code[(i+j)%len];
                }
            }
        }
        else
        {
            for(int i=0; i<len; i++)
            {
                for(int j=-1; j>=k; j--)
                {
                    ans[i] += code[(i+j+len)%len];
                }
            }
        }
        return ans;
    }
};
