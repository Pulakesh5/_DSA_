class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int length = arr.size();
        
        if(length<3)
            return false;
        
        for(int pos=2; pos<length; pos++)
        {
            if((arr[pos-2]%2)==1 && (arr[pos-1]%2)==1 && (arr[pos]%2)==1)
                return true;
        }

        return false;
    }
};
