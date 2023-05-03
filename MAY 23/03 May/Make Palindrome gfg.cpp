bool makePalindrome(int n,vector<string> &arr){
        // Code here
        map<string,int> mp;//(arr.begin(), arr.end());
        for(int i=0;i<n;i++)
            mp[arr[i]]++;
        int oddCount=0;
        for(auto it:mp)
        {
            string str = it.first;
            string rev = str;
            reverse(rev.begin(), rev.end());
            if(mp.find(rev)!=mp.end())
            {
                if(mp[str]!=mp[rev])
                {
                    //cout<<"not equal No of  straight and reverse strings\n";
                    return false;
                }
                if(str==rev)
                    oddCount+=(mp[str]%2);
                //oddCount+=(mp[str]%2);
            }
            else
            {
                //cout<<"reverse string does not exists\n";
                return false;
            }
                
        }
        return oddCount<=1;
        // cout<<oddCount<<endl;
        //return true;
    }
