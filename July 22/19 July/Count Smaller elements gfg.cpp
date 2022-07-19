class Solution{
public:	
    int pos(vector<int> aux, int target){
        int l=0,r=aux.size()-1,mid;
        while(l<=r){
            mid=(l+r)/2;
            if(aux[mid]==target){
                while(mid>0 && aux[mid-1]==aux[mid])
                    mid--;
                return mid;
            }
            else if( target>aux[mid]) l=mid+1;
            else r=mid-1;
        }
        return l;
    }
	vector<int> constructLowerArray(int *a, int n) {
	    // code here
	    map<int,vector<int>> mp;
	    for(int i=0;i<n;i++){
	        mp[a[i]].push_back(i);
	    }
	    vector<int> ans(n,0);
	    vector<int> aux;
	    aux.push_back(a[n-1]);
	    int idx;
	    for(int i=n-2;i>=0;i--){
	        idx = pos(aux, a[i]);
	        ans[i]=idx;
	        aux.insert(aux.begin()+idx, a[i]);
	    }
	    
	    return ans;
	}
};
