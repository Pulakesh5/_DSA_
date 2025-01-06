class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        // code here
        if(arr.size()<2)
            return {};
            
        sort(arr.begin(), arr.end());
        
        int closest = INT_MAX;
        vector<int> closestPair;
        int l=0, r=arr.size()-1, sum;
        
        while(l<r)
        {
            sum = arr[l] + arr[r];
            if(abs(target-sum)<closest)
            {
                closestPair = {arr[l], arr[r]};
                closest = abs(target-sum);
            }
            if(sum<target)
                l++;
            else if(sum>target) 
                r--;
            else
                return closestPair;
        }
        return closestPair;
    }
};
