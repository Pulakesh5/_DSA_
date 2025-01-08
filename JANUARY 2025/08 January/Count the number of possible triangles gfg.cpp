class Solution {
  public:
    // Function to count the number of possible triangles.
    int countTriangles(vector<int>& arr) {
        // code here
        sort(arr.begin(), arr.end());
        int n = arr.size(), lower_sides, countOfTriangle = 0;
        for(int i=0; i<(n-2); i++)
        {
            for(int j=i+1; j<(n-1); j++)
            {
                lower_sides = arr[i] + arr[j];
                
                int lb = lower_bound(arr.begin()+j+1, arr.end(), lower_sides) - arr.begin();
                
                countOfTriangle += (lb-j-1);
            }
        }
        return countOfTriangle;
    }
};
