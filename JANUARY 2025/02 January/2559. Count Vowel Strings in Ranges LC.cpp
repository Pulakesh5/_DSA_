class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int N = words.size();
        vector<int> prefixSumCount(N+5);
        int l;
        for(int i=0; i<N; i++)
        {
            l = words[i].size()-1;
            prefixSumCount[i+1] = prefixSumCount[i] + ((words[i][0]=='a' || words[i][0]=='e' || words[i][0]=='i' || words[i][0]=='o' || words[i][0]=='u') &&
                 (words[i][l]=='a' || words[i][l]=='e' || words[i][l]=='i' || words[i][l]=='o' || words[i][l]=='u'));
        }
        vector<int> replies(queries.size());
        int i=0;
        for(auto query:queries)
        {
            replies[i++] = (prefixSumCount[query[1]+1] - prefixSumCount[query[0]]);
        }
        return replies;
    }
};
