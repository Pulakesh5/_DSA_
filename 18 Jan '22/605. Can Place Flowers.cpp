/*
    Solution Idea:  Think Greedy
                    keep practising good coding practices, try not to change input data
*/
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size=flowerbed.size();
        for(int i=0;i<size && n>0;i++){
            if(flowerbed[i]!=1 && flowerbed[max(0,i-1)]==0 && flowerbed[min(size-1,i+1)]==0){
                //flowerbed[i]=1;
                n--;i++;
            }
        }
        if(n==0) return true;
        return false;
    }
};
