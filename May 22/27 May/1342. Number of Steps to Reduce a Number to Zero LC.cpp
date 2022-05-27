class Solution {
public:
    int numberOfSteps(int num) {
        if(num==0) return 0;
        int step=0;
        while(num){
            if(num%2) step+=2;
            else step+=1;
            num/=2;
        }
        return step-1;
    }
};
