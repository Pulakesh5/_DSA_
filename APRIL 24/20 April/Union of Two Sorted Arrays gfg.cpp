class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        //Your code here
        vector<int> unions;
        
        int p1=0, p2=0;
        if(arr1[0]<=arr2[0])
        {
            unions.push_back(arr1[0]);
            p1++;
        }
        else
        {
            unions.push_back(arr2[0]);
            p2++;
        }
        
        while(p1<n && p2<m)
        {
            if(arr1[p1]<=arr2[p2])
            {
                if(unions.back()<arr1[p1])
                    unions.push_back(arr1[p1]);
                p1++;
            }
            else
            {
                if(unions.back()<arr2[p2])
                    unions.push_back(arr2[p2]);
                p2++;
            }
        }
        
        while(p1<n)
        {
            if(unions.back()<arr1[p1])
                    unions.push_back(arr1[p1]);
                p1++;
        }
        
        while(p2<m)
        {
            if(unions.back()<arr2[p2])
                    unions.push_back(arr2[p2]);
                p2++;
        }
        
        return unions;
    }
};
