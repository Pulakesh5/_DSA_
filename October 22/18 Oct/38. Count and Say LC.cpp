class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        else if(n==2) return "11";
        string prev="1",curr="";
        int i=0;
        char prev_ch='$';
        int len,prev_count=0;
        while(--n)
        {
            len=prev.size();
            i=0;
            prev_ch=prev[0];
            prev_count=1;
            for(int i=1;i<len;i++)
            {
                if(prev[i]==prev_ch) prev_count++;
                else
                {
                    curr+=to_string(prev_count);
                    curr+=prev_ch;
                    prev_ch=prev[i];
                    prev_count=1;
                }
            }
            curr+=to_string(prev_count);
            curr+=prev_ch;
            prev=curr;
            curr="";
        }
        
        return prev;
    }
};
