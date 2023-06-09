class Solution
{
	public:
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    vector<string> vec;
		    int l = 0, r = S.size() - 1;
		    permute(S, l, r, vec);
		  //  sort(vec.begin(), vec.end());
		    set<string> st(vec.begin(), vec.end());
		    vector<string> ans(st.begin(), st.end());
		    return ans;
		}
		void permute(string &S, int l, int r, vector<string> &vec)
		{
		    if(l==r)
		    {
		        vec.push_back(S);
		        return;
		    }
		    set<char> swapped;

		    for(int i=l; i<=r; i++)
		    {
		        swap(S[l], S[i]);
		        permute(S, l+1, r, vec);
		        swap(S[l], S[i]);
		    }
		}
};
