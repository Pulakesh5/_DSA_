class Solution {
public:
    string gcdOfStrings(string str1, string str2) {

        int len1=str1.length(), len2=str2.length();
        
        string ans="",gcdString="";
        
        for(int l=1;l<=min(len1,len2);l++)
        {
            if(str1[l-1]!=str2[l-1])
                return "";

            ans.push_back(str1[l-1]);
            
            if(len1%l!=0 || len2%l!=0)
                continue;
            bool flag=true;

            for(int i=l;i<len1;i++)
            {
                if(ans[i%l]!=str1[i])
                {
                    flag = false;
                    break;
                }
            }

            for(int j=l;j<len2;j++)
            {
                if(ans[j%l]!=str2[j])
                {
                    flag=false;
                    break;
                }
            }
            if(flag) gcdString = ans;
        }
        return gcdString;
    }
};
