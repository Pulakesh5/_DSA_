class Solution{
    public:
    bool is_possible_to_get_seats(int n, int m, vector<int>& seats){
        // Write your code here.
        if(n==1 && m==1 && seats[0]==0) return true;
        int vacant=0, filled=0;
        int possible=0;
        
        for(int i=0;i<m;i++)
        {
            if(seats[i]==0)
                vacant++;
            else
            {
                if(filled==0)
                {
                    possible+=(vacant/2);
                }
                else
                    possible+=((vacant-1)/2);
                vacant=0;
                filled++;
            }
            
        }
        //cout<<vacant<<" "<<(vacant-1)/2<<endl;
        if(vacant)
        {
            possible+=(vacant/2);
        }
        
        // cout<<vacant<<" "<<filled<<" "<<possible<<endl;
        return possible>=n;
    }
};
