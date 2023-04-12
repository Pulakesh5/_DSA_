class Solution {
public:
    string simplifyPath(string path) {
        stack<string> stk;
        
        for(int i=0;i<path.length();i++){
            if(path[i]=='/') continue;
            string temp="";
            while(i<path.length() && path[i]!='/'){
                temp+=path[i];
                i++;
            }
            if(temp==".")
                continue;
            else if(temp=="..")
            {
                if(!stk.empty())
                    stk.pop();
            }
            else
                stk.push(temp);
        }
        
        string ans="";
        while(!stk.empty()){
            ans = '/' + stk.top() +ans;
            stk.pop();
        }
        
        if(ans.size()==0) ans="/";
        return ans;
    }
};
