class Solution
{
    public:
    //Function to find all elements in array that appear more than n/k times.
    int countOccurence(int arr[], int n, int k) {
        // Your code here
        map<int, int> count;
        for(int i=0; i<n; i++)
            count[arr[i]]++;
        int countOfOccurence=0;
        for(auto it:count)
        {
            if(it.second>(n/k))
                countOfOccurence++;
        }
        return countOfOccurence;
    }
};
