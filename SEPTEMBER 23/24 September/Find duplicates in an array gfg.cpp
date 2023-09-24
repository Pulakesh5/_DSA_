class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        // code here
        int next;
        for(int i=0; i<n; i++)
        {
            next = arr[i]%n;
            arr[next]+=n;
        }
        vector<int> duplicate;
        for(int i=0; i<n; i++)
        {
            if(arr[i]/n>1)
                duplicate.push_back(i);
        }
        if(duplicate.size()==0)
            return {-1};
        return duplicate;
    }
};
