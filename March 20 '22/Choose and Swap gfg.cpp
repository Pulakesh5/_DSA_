class Solution{
public:
    string chooseandswap(string a){
        int n=a.length();
        set<char> st;
        
        for(int i=0;i<n;i++){
            char small=a[i];
            for(int j=i+1;j<n;j++){
                if(st.find(a[j])==st.end() && small > a[j])
                    small=a[j];
            }
            
            if(small!=a[i]){
                char change = a[i];
                for(int i=0;i<n;i++){
                    if(a[i] == small) a[i]=change;
                    else if(a[i] == change) a[i]=small;
                }
                return a;
            }
            st.insert(a[i]);
        }
        return a;
    }
    
};
