class Solution {
public:
    
    bool reorderedPowerOf2(int n) {
        string nStr=to_string(n),numStr;
        long long num=1ll;
        long long lim=1ll*n*10;
        while(num<=lim){
            numStr=to_string(num);
            if(check(numStr,nStr)) return true;
            num*=2;
        }
        return false;
    }
    
    bool check(string a, string b){
        sort(b.begin(), b.end());
        sort(a.begin(), a.end());
        return a==b;
    }
};
