class Solution{
    public:
    int DivisibleByEight(string s){
        //code here
        if(s.length()>=3){
            int count=1;
            int sum=0;
            
            for(int i=s.length()-1;i>s.length()-4;i--){
                int temp=abs(s[i]-'0');
                 temp=temp*count;
                sum+=temp;
                count*=10;
                
            }
           //cout<<sum<<endl;
            if(sum%8==0)return 1;
            else return -1;
            
        }
        if(s.length()==2){
            int temp=10 * (abs('0'-s[0]));
            int temp2=abs('0'-s[1]);
            
            if(((temp+temp2)%8==0))return 1;
            else return -1;
            
        }
        if((s[0]-'0')%8==0)return 1;
        
        else return -1;
    }
};
