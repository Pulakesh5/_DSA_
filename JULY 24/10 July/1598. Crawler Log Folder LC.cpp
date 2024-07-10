class Solution {
public:
    int minOperations(vector<string>& logs) {
        int depth=0;
        for(string log:logs)
        {
            if(log=="../")
            {
                depth = max(depth-1, 0);
            }
            else if(log=="./")
                continue;
            else
                depth++;
        }
        return depth;
    }
};
