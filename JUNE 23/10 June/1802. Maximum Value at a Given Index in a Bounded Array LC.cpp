class Solution
{
    public:
        void Rearrange(int arr[], int n)
        {
            // Your code goes here
            int neg = 0;
            vector<int> v;
            for(int i=0; i<n; i++)
            {
                if(arr[i]<0)
                {
                    v.insert(v.begin()+neg,arr[i]);
                    neg++;                    
                }
                else
                    v.push_back(arr[i]);
            }
            for(int i=0; i<n; i++)
                arr[i] = v[i];
        }
};
