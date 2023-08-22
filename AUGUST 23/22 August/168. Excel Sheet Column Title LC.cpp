class Solution {
public:
    string convertToTitle(int columnNumber) {
        string Title="";
        while(columnNumber)
        {
            if(columnNumber%26 == 0)
            {
                Title.push_back('Z');
                columnNumber--;
            }
            else
                Title.push_back(columnNumber%26 - 1+'A');
            columnNumber/=26;
        }
        reverse(Title.begin(), Title.end());
        return Title;
    }
};
