class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n=arr.size();
        int peak=0,plateau=0;
        for(int i=1;i<n-1;i++){
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1])
                peak++;
            else if(arr[i]>arr[i-1] && arr[i]==arr[i+1] ||
                    arr[i]>arr[i+1] && arr[i]==arr[i-1] || 
                    arr[i]<arr[i-1] && arr[i]<arr[i+1]  ||
                    arr[i]==arr[i-1] && arr[i]==arr[i+1])
                plateau++;
        }
        if(peak==1 && plateau==0)
            return true;
        return false;
            
    }
};
//////////////////////   Elegant Solution   //////////////////////////
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n=arr.size();
        int l=0,r=n-1;
        
        while(l+1<n && arr[l]<arr[l+1]) 
            l++;
        while(r>0 && arr[r]<arr[r-1])
            r--;
        return l>0 && r<n-1 && l==r;
            
    }
};
