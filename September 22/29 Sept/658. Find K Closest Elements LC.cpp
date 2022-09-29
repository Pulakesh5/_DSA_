class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int lp=lower_bound(arr.begin(),arr.end(),x)-arr.begin();
        int n=arr.size(),i,j;
        vector<int> closest;
        //cout<<lp;
        if(lp<n)
        {
            i=lp-1;
            j=lp;
            while(i>=0 && j<n && k){
                if(abs(arr[i]-x)<abs(arr[j]-x))
                {
                    closest.push_back(arr[i--]);
                }
                else if(abs(arr[i]-x)>abs(arr[j]-x))
                {
                    closest.push_back(arr[j++]);
                }
                else
                {
                    if(arr[i]<=arr[j])
                    {
                        closest.push_back(arr[i--]);
                    }
                    else
                        closest.push_back(arr[j++]);
                }
                k--;
            }
            while(k && i>=0)
            {
                closest.push_back(arr[i--]);
                k--;
            }
            while(k && j<n)
            {
                closest.push_back(arr[j++]);
                k--;
            }
        }
        else
        {
            i=lp-1;
            while(k && i>=0)
            {
                closest.push_back(arr[i--]);
                k--;
            }
        }
        sort(closest.begin(),closest.end());
        return closest;
    }
};
