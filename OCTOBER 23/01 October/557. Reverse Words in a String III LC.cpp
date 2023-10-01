class Solution {
public:
    string rev(string word)
    {
        reverse(word.begin(), word.end());
        return word;
    }
    string reverseWords(string s) {
        stringstream ss(s);
        string word="";
        vector<string> words;
        while(ss>>word)
            words.push_back(word);
        string reverse = "";
        for(int i=0; i<(words.size()-1); i++)
        {
            reverse+=rev(words[i]);
            reverse.push_back(' ');
        }

        reverse+=rev(words[words.size()-1]);
        
        return reverse;

    }
};
