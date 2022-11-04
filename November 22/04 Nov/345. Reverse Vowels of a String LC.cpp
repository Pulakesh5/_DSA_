class Solution {
public:
    string reverseVowels(string s) {
        vector<char> vec;
        for(char ch:s)
        {
            if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'||
               ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U'
            )
                vec.push_back(ch);
        }
        reverse(vec.begin(),vec.end());
        int n=s.size(), k=0;
        char ch;
        for(int i=0;i<n;i++)
        {
            ch=s[i];
            if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'||
               ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U'
            )
                s[i]=vec[k++];
        }        
        return s;
    }
};
