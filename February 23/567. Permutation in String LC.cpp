class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int length2=s2.size(), length1=s1.size();

        if(length2<length1) return false;

        vector<int> count_s1(26,0), count_substr(26,0);
        
        for(char ch:s1)
            count_s1[ch-'a']++;

        for(int i=0;i<length1;i++)
            count_substr[s2[i]-'a']++;
        
        for(int i=length1;i<length2;i++)
        {
            if(count_s1==count_substr) return true;
            count_substr[s2[i-length1]-'a']--;
            count_substr[s2[i]-'a']++;
        }

        return (count_s1==count_substr);
    }
};
