class Solution{
    public:
    // void printBits(int x)
    // {
    //     string s = "";
    //     int pos = 0;
    //     while(pos<30)
    //     {
    //         s += (x%2+'0');
    //         x/=2;
    //         pos++;
    //     }
    //     reverse(s.begin(), s.end());
    //     cout<<s<<endl;
    // }
    int setSetBit(int x, int y, int l, int r){
        // code here
        int modifiedX = 0, pos = 1, expo = 1;
        // printBits(x);
        // printBits(y);
        while(pos<=r || x)
        {
            if((x%2)==1 || (pos>=l && pos<=r && (x%2)==0 && (y%2)==1))
                modifiedX+=expo;
            expo = expo<<1;
            x/=2;
            y/=2;
            pos++;
        }
        return modifiedX;
    }
};
