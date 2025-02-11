class Solution {
public:
    string removeOccurrences(string s, string part) {
        int len = s.size();
        string removedString = "";
        // removedString.push_back(s[0]);
        for(int i=0; i<len; i++)
        {
            removedString.push_back(s[i]);
            string aux = "";
            int k=part.size()-1;
            while(removedString.size() && k>=0 && removedString.back()==part[k--])
            {
                aux.push_back(removedString.back());
                removedString.pop_back();
            }
            if(aux.size()<part.size())
            {
                reverse(aux.begin(), aux.end());
                removedString += aux;
            }
        }
        return removedString;
    }
};
