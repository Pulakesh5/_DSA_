class Solution {
public:
    string largestOddNumber(string num) {
        int i=num.size()-1;
        while(i>-1)
        {
            if((num[i]-'0')%2)
                break;
            i--;
        }
        return num.substr(0,i+1);
    }
};
