class Solution {
public:
    unsigned int position(vector<int> &aux, int element){
        int l=0,r=aux.size()-1,mid;
        
        while(l<=r){
            mid=(l+r)/2;
            if(aux[mid]==element){
                while(mid>0 && aux[mid-1]==element)
                    mid--;
                return mid;
            }
            else if(aux[mid]>element) r=mid-1;
            else l=mid+1;
        }
        return l;
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<int> aux,ans(n,0);
        aux.push_back(nums[n-1]);
        
        int pos;
        for(int i=n-2;i>=0;i--){
            pos=position(aux,nums[i]);
            ans[i] = pos;
            aux.insert(aux.begin()+pos, nums[i]);
        }
        return ans;
    }
};
