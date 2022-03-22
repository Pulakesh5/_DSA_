vector<int> Smallestonleft(int arr[], int n)
{
    set<int> st;
    vector<int> ans;
    for(int i=0;i<n;i++){
        st.insert(arr[i]);
        auto it=st.find(arr[i]);
        if(it==st.begin())
            ans.push_back(-1);
        else{
            it--;
            ans.push_back(*it);
        }
    }
    return ans;
}
