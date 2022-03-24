class Solution {
public:
    int brokenCalc(int target, int start) {
        int ans=0;
        while(start>target){
            if((start%2)==0) start/=2;
            else start+=1;
            ans++;
        }
        return ans + (target-start);
    }
};
