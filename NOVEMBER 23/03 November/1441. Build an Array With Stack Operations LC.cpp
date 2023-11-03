class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> operations;
        int last=0;
        for(int i=1; i<target[0]; i++)
        {
            operations.push_back("Push");
            operations.push_back("Pop");
            // cout<<"push pop "<<i<<endl;
            last = i;
        }
        last = target[0];
        for(int num:target)
        {
            while(last<num)
            {
                operations.push_back("Push");
                operations.push_back("Pop");
                // cout<<"push pop "<<last<<endl;
                last++;
            }
            operations.push_back("Push");
            // cout<<"push "<<num<<endl;
            last = num+1;
        }
        return operations;
    }
};
