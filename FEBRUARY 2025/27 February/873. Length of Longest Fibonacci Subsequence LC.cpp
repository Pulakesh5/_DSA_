class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int N = arr.size();
        unordered_set<int> st(arr.begin(), arr.end());
        int longestFibSubseq = 0;
        for(int i=0; i<N; i++)
        {
            for(int j=i+1; j<N; j++)
            {
                int a = arr[i], b = arr[j], l=2;
                while(st.count(a+b))
                {
                    b = a+b;
                    a = b-a;
                    l++;
                }
                longestFibSubseq = max(longestFibSubseq, l);
            }
        }
        return (longestFibSubseq > 2 ? longestFibSubseq : 0);
    }
};
