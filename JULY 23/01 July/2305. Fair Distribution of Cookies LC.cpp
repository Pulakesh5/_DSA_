class Solution {
public:
    int minUnfairness = INT_MAX;
    void backtrack(vector<int> &cookies, int index, int k, vector<int> &distribution)
    {
        int n = cookies.size();
        int unfairness = INT_MIN, obtained = 0, c = 0, ret;
        if(index == n)
        {
            for(int i=0; i<k; i++)
                unfairness = max(unfairness, distribution[i]);
            minUnfairness = min(minUnfairness, unfairness);
            return;
        }
        else
        {
            for(int i=0; i<k ;i++)
            {
                distribution[i] += cookies[index];
                backtrack(cookies, index+1, k, distribution);   
                distribution[i] -= cookies[index];
            }
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size(), index = 0 ;
        vector<int> distribution(k);
        backtrack(cookies, index, k, distribution);
        return minUnfairness;
    }
};
