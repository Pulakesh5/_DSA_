class Solution{
	public:
	bool check_elements(int arr[], int n, int A, int B)
	{
        // Your code goes here
        bool check = true;
        unordered_map<int,int>mp;
        //Store all values into a map
        for(int i=0;i<n;i++) mp[arr[i]]++;
        
        //Find if elements in the given range is present in the map or not
        for(int i = A;i<=B;i++){
            if(mp.find(i) == mp.end()) return false;
	   }
	   return check;
	}
};
