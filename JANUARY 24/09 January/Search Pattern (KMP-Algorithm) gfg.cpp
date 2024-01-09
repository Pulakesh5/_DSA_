class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            //code here
            vector<int> ans;
            for(int i=0;i<txt.size();i++){
                int a=0;
                int b=i;
                int count=0;
                while(pat[a] && txt[b] && pat[a]==txt[b] ){
                   a++; 
                   b++;
                   count++;
                }
                if(count==pat.size()) ans.push_back(i+1);
            }
            return ans;
        }
     
};
