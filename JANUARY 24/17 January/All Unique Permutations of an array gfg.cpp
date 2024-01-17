class Solution {
  public:
    set<vector<int>> St;
    vector<vector<int>> ans;
       void helper(int ind , int n, vector<int> arr){

            if(ind == n){
         St.insert(arr);

          }else{

          for(int i=ind; i<n; i++){

             swap(arr[ind], arr[i]);

             helper(ind+1, n, arr);

             swap(arr[ind], arr[i]);

          }

        }

          

      }
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n){

         helper(0,n,arr);

           for(auto x : St)

        ans.push_back(x);

            return ans;

    }


};
