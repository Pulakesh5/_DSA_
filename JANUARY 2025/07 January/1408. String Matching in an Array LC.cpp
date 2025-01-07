class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        size_t N = words.size();
        vector<string> substrings;

        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                if(i!=j)
                {
                    auto found = words[j].find(words[i]);
                    if(found!=string::npos)
                    {
                        substrings.push_back(words[i]);
                        break;
                    }
                }
            }
        }
        return substrings;
    }
};
