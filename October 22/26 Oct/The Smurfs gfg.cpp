
class Solution{
public:
    int findMin(int n, char a[]){
        // code here
        int r=0,g=0,b=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]=='R') r++;
            else if(a[i]=='B') b++;
            else g++;
        }
        if(r%2 && b%2 && g%2 || !(r%2) && !(g%2) && !(b%2)) return 2;
        return 1;
    }
};
