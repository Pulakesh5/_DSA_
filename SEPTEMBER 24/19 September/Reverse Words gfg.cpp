class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string str) {
        // code here
        string word = "";
        vector<string> words;
        int index = 0;
        for(int index = 0; index<str.size(); index++)
        {
            if(str[index]=='.')
            {
                // cout<<word<<endl;
                words.push_back(word);
                word = "";
            }
            else
                word.push_back(str[index]);
        }
        if(word.size())
            words.push_back(word);
        
        string reversedString = "";
        int NumOfWords = words.size();
        // cout<<endl;
        for(int i=NumOfWords-1; i>0 ; i--)
        {
            // cout<<words[i]<<endl;
            reversedString += words[i];
            reversedString.push_back('.');
        }
        reversedString += words[0];
        return reversedString;
    }
};
