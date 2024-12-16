class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        // code here
        int len_a = a.size(), len_b = b.size();
        int i=0, j=0;
        while(--k && i<len_a && j<len_b)
        {
            if(a[i]<=b[j])
                i++;
            else
                j++;
            // cout<<i<<' '<<j<<endl;
        }
        while(k && i<len_a)
        {
            i++;
            k--;
        }
        while(k && j<len_b)
        {
            j++;
            k--;
        }
        if(i<len_a && j<len_b)
            return min(a[i], b[j]);
        if(i<len_a)
            return a[i];
        return b[j];
    }
};
