class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        
        vector<unordered_set<string>> groups(26);
        
        for(string idea:ideas)
            groups[idea[0]-'a'].insert(idea.substr(1));
        
        long long count=0,remove=0;

        for(int i=0;i<26;i++)
        {
            for(int j=i+1;j<26;j++)
            {
                unordered_set<string> st;
                st.insert(groups[i].begin(),groups[i].end());
                st.insert(groups[j].begin(),groups[j].end());

                count+= (groups[i].size()-st.size())*(groups[j].size()-st.size());
            }
            
        }
        
        count*=2;

        return count;
    }
};
