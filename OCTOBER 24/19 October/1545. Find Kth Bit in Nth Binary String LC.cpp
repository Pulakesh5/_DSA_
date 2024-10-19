class Solution {
public:
    char findKthBit(int n, int k) {
        int invert = 0;
        int exp = (1<<n)-1;
        while(k>1)
        {
            cout<<n<<" "<<k<<endl;
            if(k==exp/2+1)
                return '0'+(invert^1);
            if(k>exp/2)
            {
                k = (exp+1)-k;
                invert = 1-invert;
            }
            exp/=2;
        }
        return (char)('0'+invert);
    }
};
