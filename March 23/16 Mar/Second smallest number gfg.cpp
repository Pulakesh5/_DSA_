class Solution{   
  public:
    string secondSmallest(int S, int D){
        // code here 
        if(S>=(D*9)) return "-1";
        string number;
        int last, digit;
        for(int i=0; i<D; i++)
        {
            digit = min(9,S);
            S-=digit;
            //cout<<i<<" : "<<digit<<endl;
            number.push_back('0'+digit);
            if(digit>0) last = i;
        }
        if(number[D-1]=='0')
        {
            number[D-1]='0'+1;
            number[last]--;
        }
        //cout<<"ur : "<<number<<endl;
        
        if(D-1==last+1)
            last++;
        reverse(number.begin(), number.end());
        //cout<<"r : "<<number<<endl;
        last=D-1;
        while(last>0 && number[last]=='9')
            last--;
        if(last<(D-1))
        {
            number[last]++;
            number[last+1]--;
        }
        else if(last>0)
        {
            number[last]--;
            number[last-1]++;
        }
        else
            return "-1";
        //cout<<number<<endl;
        return number;
    }
};
