//bit set method of generating subsets
class Solution
{
    public:
    //Function to find all possible unique subsets.
    vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {
        set<vector<int>> set_vector;
        for(int i=0;i<(1<<n);i++){
            bitset<12> bits(i);
            vector<int> vec;
            for(int i=0;i<n;i++){
                if(bits[i]) vec.push_back(arr[i]);
            }
            if(vec.size())
                sort(vec.begin(),vec.end());
        
            set_vector.insert(vec);
        }
        vector<vector<int>> ans(set_vector.begin(), set_vector.end());
        return ans;
    }
};
//BackTracking method of solution
class Solution
{
    vector<vector<int>> ans;
    public:
    //Function to find all possible unique subsets.
    void backtrack(int ind, int n, vector<int> &subset, vector<int> &arr){
        ans.push_back(subset);
        for(int i=ind;i<n;i++){
            subset.push_back(arr[i]);
            backtrack(i+1,n,subset,arr);
            subset.pop_back();
            while(i<(n-1) && arr[i]==arr[i+1])
            i++;
        }
    }
    vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {
        sort(arr.begin(), arr.end());
        vector<int> subset;
        backtrack(0,n,subset,arr);
        return ans;
    }
};
