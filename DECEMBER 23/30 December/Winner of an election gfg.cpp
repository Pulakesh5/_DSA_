class Solution{
  public:
  
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[],int n)
    {
        // Your code here
        // Return the string containing the name and an integer
        // representing the number of votes the winning candidate got
        sort(arr,arr+n);
        int i=0;
        int vote=0, majority=0;
        string candidate;
        vector<string> ans;
        while(i<n)
        {
            candidate=arr[i++];
            vote=1;
            while(i<n && candidate==arr[i])
            {
                vote++;
                i++;
            }
            if(vote>majority)
            {
                majority=vote;
                ans.clear();
                ans.push_back(candidate);
                ans.push_back(to_string(vote));
            }
        }
        return ans;
    }
};
