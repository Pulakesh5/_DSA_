class Solution{
public:
    int count = 2;
    bool isLucky(int n) {
        // code here
        if(n<count)
            return true;
        if(n%count == 0)
            return false;
        n = n - n/count;
        
        count++;
        
        return isLucky(n);
    }
};
