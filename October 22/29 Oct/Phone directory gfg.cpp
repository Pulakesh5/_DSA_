    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        set<string> vec;
        for(int i=0;i<n;i++)
            if(s[0]==contact[i][0])
                vec.insert(contact[i]);
        //sort(vec.begin(),vec.end());
        vector<vector<string>> ans;
        vector<string> v;
        if(vec.size()==0)
                ans.push_back({"0"});
        else
            {
                v.clear();
                for(string str:vec) v.push_back(str);
                ans.push_back(v);
            }
        for(int i=1;i<s.size();i++)
        {
            set<string> temp;
            for(string str: vec)
                if(str.size()>i && str[i]==s[i])
                    temp.insert(str);
                    
            if(temp.size()==0)
                ans.push_back({"0"});
            else
            {
                v.clear();
                for(string str:temp)
                    v.push_back(str);
                ans.push_back(v);
            }
            vec=temp;
        }
        
        return ans;
    }
