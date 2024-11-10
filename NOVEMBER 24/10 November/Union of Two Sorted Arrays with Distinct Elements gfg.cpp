class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // Your code here
        // return vector with correct order of elements
        vector<int> unionArray;
        int ia = 0, ib = 0;
        int lena = a.size(), lenb = b.size();
        while(ia<lena && ib<lenb)
        {
            if(a[ia]==b[ib])
            {
                unionArray.push_back(a[ia]);
                ia++;
                ib++;
            }
            else if(a[ia]<b[ib])
            {
                unionArray.push_back(a[ia]);
                ia++;
            }
            else
            {
                unionArray.push_back(b[ib]);
                ib++;
            }
        }
        
        while(ia<lena)
            unionArray.push_back(a[ia++]);
        
        while(ib<lenb)
            unionArray.push_back(b[ib++]);
        
        return unionArray;
    }
};
