class Solution {
  public:
    // Function to return the count of number of elements in union of two arrays.
    int findUnion(vector<int>& a, vector<int>& b) {
        // code here
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        vector<int> _union;
        int l=0, r=0;
        int len_a = a.size(), len_b = b.size(), last=-1;
        int union_count = 1;
        if(a[0]<=b[0])
            last = a[l++];
        else
            last = b[r++];
        
        while(l<len_a && r<len_b)
        {
            if(a[l] < b[r])
            {
                if(last!=a[l])
                {
                    last = a[l];
                    union_count++;
                }
                l++;
            }
            else if(a[l] > b[r])
            {
                if(last!=b[r])
                {
                    last = b[r];
                    union_count++;
                }
                r++;
            }
            else
            {
                if(last!=a[l])
                {
                    last = a[l];
                    union_count++;
                }
                l++;
                r++;
            }
        }
        while(l<len_a)
        {
            if(last!=a[l])
            {
                last = a[l];
                union_count++;
            }
            l++;
        }
        
        while(r<len_b)
        {
            if(last!=b[r])
            {
                last = b[r];
                union_count++;
            }
            r++;
        }
        return union_count;
    }
};
