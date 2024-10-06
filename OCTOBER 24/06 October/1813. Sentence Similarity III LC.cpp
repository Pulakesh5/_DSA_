class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        deque<string> words1, words2;
        stringstream ss1(sentence1), ss2(sentence2);
        string word;
        while(getline(ss1, word, ' '))
            words1.push_back(word);
        while(getline(ss2, word, ' '))
            words2.push_back(word);
        
        if(words1==words2)
            return true;
        if(words1.size()>words2.size())
            swap(words1, words2);
        while(words1.size()!=0)
        {
            if(words1.back() == words2.back())
            {
                words1.pop_back();
                words2.pop_back();
            } else if(words1.front() == words2.front()) {
                words1.pop_front();
                words2.pop_front();
            } else {
                break;
            }
        }

        return (words1.size()==0);
    }
};
