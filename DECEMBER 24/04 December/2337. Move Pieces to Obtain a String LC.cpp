class Solution {
public:
    bool canChange(string start, string target) {
        int lenStart = start.size(), lenTarget = target.size();
        if(lenStart != lenTarget)
            return false;
        int i=0, j=0;
        while(i<lenStart && j<lenTarget)
        {
            // skips _ 
            while(i<lenStart && start[i]=='_')
                i++;
            while(j<lenTarget && target[j]=='_')
                j++;
            // character mismatch
            if(start[i]!=target[j])
                return false;
            // direction mismatch
            if((start[i]=='L' && i<j) || (start[i]=='R' && i>j))
                return false;
            i++;
            j++;
        }
        // skips _ 
        while(i<lenStart && start[i]=='_')
            i++;
        while(j<lenTarget && target[j]=='_')
            j++;
        return (i>=lenStart && j>=lenTarget);
    }
};
