class Solution{
  public:
    //Function to find triplets with zero sum.
    bool findTriplets(int arr[], int n)
    { 
        //Your code here
        int j, k, tripletSum;
        sort(arr, arr+n);
        for(int i=0; i<(n-2); i++)
        {
            j = i+1;
            k = n-1;
            
            while(j<k)
            {
                tripletSum = arr[i] + arr[j] + arr[k]; 
                if(tripletSum==0)
                    return true;
                else if(tripletSum<0)
                    j++;
                else
                    k--;
            }
        }
        return false;
    }
};
