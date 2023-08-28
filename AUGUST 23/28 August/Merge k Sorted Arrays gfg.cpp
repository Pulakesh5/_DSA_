class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        //code here
        vector<int> sorted;

        for(int i=0; i<k; i++)
        {
            for(int j=0; j<k; j++)
                sorted.push_back(arr[i][j]);
        }
        sort(sorted.begin(), sorted.end());
        return sorted;
    }
};
