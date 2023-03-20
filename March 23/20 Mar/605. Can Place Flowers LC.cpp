class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int sz = flowerbed.size();
        for(int i=0;i<sz && n;i++)
        {
            if(flowerbed[i]==0 && flowerbed[max(0,i-1)]!=1 && flowerbed[min(i+1,sz-1)]!=1)
            {
                n--;
                i++;
            }
        }
        return (n==0);
    }
};
