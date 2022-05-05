class Solution{   
public:
    string stringPartition(string str, int a, int b){
        // str = num1 + num2;
        int n=str.length();
        if(n<2) return "-1";
        
        vector<long long> arr(n-1,0); //except the first digit which is must for num1
        
        int ten_pow=10;
        arr[n-2]=str[n-1]-'0';
        
        for(int i=n-2;i>0;i--){
            int num=(str[i]-'0') * ten_pow + arr[i];
            arr[i-1]=num;
            ten_pow*=10;
        }
        
        string ans="";
        int val=0;
        int i=0;
        while(i<n-1){
            ans+=str[i];
            val = val*10 + (str[i]-'0');
            if(!(val%a) && !(arr[i]%b))
            {
                ans+= " ";
                ans+=str.substr(i+1);
                return ans;
            }
            i++;
        }
        return "-1";
        
        
    }
};
