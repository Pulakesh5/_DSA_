class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        if(buckets==1) return 0;
        int pigs=1,test=(1+minutesToTest/minutesToDie);
        int count=test;
        while(count<buckets){
            count*=test;
            pigs++;
        }
        return pigs;
    }
};
