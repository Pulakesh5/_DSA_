class Solution {

  public:
    int maxWater(vector<int> &a) {
        // code here
        int N = a.size();
        int l = 0, r=N-1;
        int maxiWater = 0, tmp;
        while(l<r)
        {
            tmp = min(a[l], a[r])*(r-l);
            maxiWater = max(maxiWater, tmp);
            if(a[l]<a[r])
                l++;
            else
                r--;
        }
        return maxiWater;
    }
};
