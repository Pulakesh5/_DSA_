class Solution{
    public:
    vector<int> canMakeTriangle(vector<int> arr, int n){
        vector<int> ans(n-2,1);
        for(int i=0;i<(n-2);i++){
            int a=arr[i], b=arr[i+1], c=arr[i+2];
            
            if( (a+b)<=c || (a+c)<=b || (c+b)<=a)
                ans[i]=0;
        }
        return ans;
    }
}; 
