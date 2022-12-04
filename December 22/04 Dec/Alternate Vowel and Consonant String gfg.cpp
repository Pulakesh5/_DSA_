    string rearrange (string S, int N)
    {
        // your code here
        set<char> vowels={'a','e','i','o','u','A','E','I','O','U'};
        
        string vowl,cons;
        for(char ch:S)
        {
            if(vowels.find(ch)!=vowels.end()) vowl.push_back(ch);
            else    cons.push_back(ch);
        }
        
        sort(vowl.begin(), vowl.end());
        sort(cons.begin(), cons.end());
        
        int vs=vowl.size(), cs=cons.size();
        
        if(abs(vs-cs)>1) return "-1";
        
        string ans="";
        if(vs>cs || (vs==cs && vowl>cons))
        {
            cout<<vowl<<" "<<cons<<endl;
            while(cons.size() && vowl.size())
            {
                ans.push_back(vowl.back());
                vowl.pop_back();
                ans.push_back(cons.back());
                cons.pop_back();
            }
        }
        else if(cs>vs || (vs==cs && vowl<cons)){
            cout<<vowl<<" "<<cons<<endl;
            while(cons.size() && vowl.size())
            {
                ans.push_back(cons.back());
                cons.pop_back();
                ans.push_back(vowl.back());
                vowl.pop_back();
            }
        }
        
        if(vowl.size()) ans.push_back(vowl.back());
        if(cons.size()) cons.push_back(cons.back());
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
