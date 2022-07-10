class SmallestInfiniteSet {
public:
    set<int> st;
    SmallestInfiniteSet() {
        for(int i=1;i<=1000;i++)
            st.insert(i);
    }
    
    int popSmallest() {
        int ans=*st.begin();
        st.erase(ans);
        return ans;
    }
    
    void addBack(int num) {
        st.insert(num);
    }
};
