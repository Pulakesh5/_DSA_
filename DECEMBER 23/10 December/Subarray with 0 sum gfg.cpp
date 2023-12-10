class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        //Your code here
        set<int> sumExisted;
        sumExisted.insert(0);
        int sum=0;
        for(int i=0; i<n; i++)
        {
            sum+=arr[i];
            if(sumExisted.find(sum)!=sumExisted.end())
                return true;
            sumExisted.insert(sum);
        }
        return false;
    }
};
