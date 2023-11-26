class Solution{
public:
    vector<int> pattern(int N){
        // code here
        if(N==0)
            return {0};
        int diff_neg=-5, diff_pos=5, n=N;
        vector<int> v;
        bool flag=true;
        while(n<=N)
        {
            v.push_back(n);
            if(flag)
                n-=5;
            else
                n+=5;
            if(n<=0)
                flag = false;
        }
        
        return v;
    }
};
