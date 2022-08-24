vector<string>ans;
    vector<string> genIp(string &s) {
        if(s=="0000")return vector<string>({"0.0.0.0"});

        if(s.size()<4 || s.size()>12)return vector<string>();
        string res="";
        dp(s,0,res,0);
        return ans;
    }
    
    void dp(string s, int i,string res,int dots){
        
        if(i>s.size()-1 && dots==4){
            res.pop_back();
            ans.push_back(res);
            return ;
        }

        if(dots>=4 )return;
        for(int j=1;j<=i+3 && i+j<=s.size();j++){
            if(s[i]=='0' && j>1)return;
            if(stoi(s.substr(i,j))<256){
                auto temp=res+s.substr(i,j)+".";
                dp(s,i+j,temp,dots+1);
            }
        }

    }
