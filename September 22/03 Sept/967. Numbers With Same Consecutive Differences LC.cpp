class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> prevNums={1,2,3,4,5,6,7,8,9},curNums;
        int lastDigit;
        for(int dig=2;dig<=n;dig++)
        {
            curNums.clear();
            for(auto num:prevNums)
            {
                lastDigit=(num%10);
                
                if(lastDigit+k<10)
                    curNums.push_back(num*10+lastDigit+k);
                if(k>0 && (lastDigit-k)>=0)
                    curNums.push_back(num*10+lastDigit-k);
            }
            prevNums=curNums;
        }
        return prevNums;
        
    }
};
