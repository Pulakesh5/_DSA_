class Solution {
  public:
    vector<int> intersectionWithDuplicates(vector<int>& a, vector<int>& b) {
        // code here
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        vector<int> intersection;
        int len_a = a.size(), len_b = b.size();
        int i=0, j=0;
        while(i<len_a && j<len_b)
        {
            if(a[i]<b[j])
                i++;
            else if(a[i]>b[j])
                j++;
            else
            {
                if(intersection.empty() || intersection.back()!=a[i])
                    intersection.push_back(a[i]);
                i++;
                j++;
            }
        }
        return intersection;
    }
};
