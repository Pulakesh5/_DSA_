class Solution {
public:
    string convert(string s, int numRows) {
        vector<vector<char>> vec(numRows);
        int pos=0, row=0;
        int length=s.size();

        while(pos<length)
        {
            row=0;
            while(pos<length && row<numRows)
                vec[row++].push_back(s[pos++]);

            row-=2;

            while(pos<length && row>0)
                vec[row--].push_back(s[pos++]);
        }
        string zigzag="";
        for(vector<char> v:vec)
        {
            for(char ch:v)
                zigzag.push_back(ch);
        }

        return zigzag;
    }
};
