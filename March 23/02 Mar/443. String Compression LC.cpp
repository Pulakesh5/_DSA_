class Solution {
public:
    int countDigit(int num)
    {
        if(num<=1) return 0;

        int count=0;
        while(num)
        {
            count++;
            num/=10;
        }
        return count;
    }
    int compress(vector<char>& chars) {
        int n = chars.size();
        char lastChar=chars[0];
        int lastCount=1;
        int ans=0;
        vector<char> compressed(n);
        int k=0;
        for(int i=1;i<n;i++)
        {
            if(chars[i]==lastChar)
            {
                lastCount++;
                continue;
            }
            //cout<<lastChar<<" "<<lastCount<<endl;
            compressed[k++]=lastChar;
            ans+=countDigit(lastCount);
            ans++;
            if(lastCount!=1)
            {
                string temp="";
                while(lastCount)
                {
                    temp.push_back(lastCount%10+'0');
                    lastCount/=10;
                }
                reverse(temp.begin(),temp.end());
                for(char ch:temp)
                    compressed[k++]=ch;
            }
            
            
            lastCount=1;
            lastChar=chars[i];
        }
        compressed[k++]=lastChar;
        if(lastCount!=1)
        {
            string temp="";
            while(lastCount)
            {
                temp.push_back(lastCount%10+'0');
                lastCount/=10;
            }
            reverse(temp.begin(),temp.end());
            for(char ch:temp)
                compressed[k++]=ch;
        }
        //cout<<lastChar<<" "<<lastCount<<endl;
        ans+=countDigit(lastCount);
        ans++;
        chars=compressed;

        // for(char ch:chars) cout<<ch<<" ";
        // cout<<endl;

        return k;
    }
};
