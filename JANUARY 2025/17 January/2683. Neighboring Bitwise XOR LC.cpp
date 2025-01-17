class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int len = derived.size();
        if(len<2)
            return 1-derived[0];
        int rest = 0, last;
        // make the last element 0 and do a trial, if satisfies true
        for(int i=len-2; i>-1; i--)
        {
            last = (rest^derived[i]);
            rest = last;
        }
        if(derived[len-1]==last)
            return true;
        rest = 1;        
        // make the last element 1 and do a trial, if satisfies true
        for(int i=len-2; i>-1; i--)
        {
            last = (rest^derived[i]);
            rest = last;
        }
        if(derived[len-1]==(last^1))
            return true;
        // if 0 and 1 both didn't work, array doest not exists
        return false;
    }
};
