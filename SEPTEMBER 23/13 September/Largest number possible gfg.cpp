class Solution{
public:
    string findLargest(int n, int S){
        // code here
        
            
        string num = "";
        int mn, N=n;
        if(N*9<S)
            return "-1";
        while(N && S)
        {
            mn = min(9,S);
            num.push_back('0'+mn);
            S-=mn;
            N--;
        }
        
        while(N--)
            num.push_back('0');
        // cout<<N<<" "<<num<<endl;
        if(num[0]=='0' && n>1)
            return "-1";
        return num;
    }
};
