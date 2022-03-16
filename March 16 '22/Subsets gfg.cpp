//BitSet Approach
class Solution
{
    public:
    vector<vector<int> > subsets(vector<int>& A)
    {
        int n=A.size();
        vector<vector<int>> ans;
        for(int i=1;i<=(1<<n);i++){ // all combination of bitlength n
            bitset<20> bt=i;
            vector<int> vec;
            for(int i=0;i<n;i++){
                if(bt[i])
                    vec.push_back(A[i]);
            }
            ans.push_back(vec);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//BackTracking Approach
class Solution
{
   vector<vector<int>> subsetsRes; //global vector declaration

   //recursive helper function
   void generate(vector<int>& A, int i, vector<int>& nums){
   
       if(i==A.size()){
           subsetsRes.push_back(nums);
           return;
       }    // base case 
       nums.push_back(A[i]);
      generate(A, i+1, nums); // Case in which element considered is  added
      nums.pop_back();
      generate(A, i+1, nums); // Case in which element considered is not added
       //backtrack
   }
   public:
   vector<vector<int>> subsets(vector<int>& A)
   {
       //code here
       vector<int> nums;
       generate(A, 0, nums);
       sort(subsetsRes.begin(), subsetsRes.end());
       return subsetsRes;
   }
};
