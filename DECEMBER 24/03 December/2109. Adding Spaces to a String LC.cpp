class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string addedSpace = "";
        string word = "";
        int index=0, Length = s.size();
        for(int space:spaces)
        {
            while(index<Length)
            {
                if(index<space)
                {
                    word.push_back(s[index++]);
                }
                else if(index==space)
                {
                    addedSpace += word;
                    addedSpace.push_back(' ');
                    word = "";
                    break;
                }
            }
        }
        while(index<Length)
        {
            word.push_back(s[index++]);
        }
        if(word.size())
            addedSpace += word;
        return addedSpace;
    }
};
