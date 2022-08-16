class Solution {
public:
    int reverse(int x) {

        long long temp_num=(x<0?(-1ll*x):x),num=0;
        
        while(temp_num){
            //cout<<num<<" "<<temp_num%10<<endl;
            num=num*10+(temp_num)%10;
            temp_num/=10;
            //cout<<num<<" "<<temp_num<<endl;
            if(num<INT_MIN || num>INT_MAX) return 0;
        }
        return (x<0?(-1*num):num);
        
    }
};
