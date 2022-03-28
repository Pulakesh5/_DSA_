class Solution{
public:    
    int swapBits(int x, int p1, int p2, int n)
    {
        bitset<32> bits(x);
        for(int i=0;i<n;i++){
            int temp=bits[p1+i];
            bits[p1+i]=bits[p2+i];
            bits[p2+i]=temp;
        }
        return bits.to_ulong();
    }
};
