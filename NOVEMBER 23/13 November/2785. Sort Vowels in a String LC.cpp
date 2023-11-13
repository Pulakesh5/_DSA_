class Solution {
public:
    string sortVowels(string s) {
        string sortedS="";
        string vowels="";
        set<char> vowelset={'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        for(int i=0; i<s.size(); i++)
        {
            if(vowelset.find(s[i])!=vowelset.end())
                sortedS.push_back('$'), vowels.push_back(s[i]);
            else
                sortedS.push_back(s[i]);
        }
        cout<<sortedS<<endl;
        sort(vowels.begin(), vowels.end(), greater<int>());
        for(int i=0; i<s.size(); i++)
        {
            if(sortedS[i]!='$')
                continue;
            sortedS[i] = vowels.back();
            vowels.pop_back();
        }
        return sortedS;
    }
};
