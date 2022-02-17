//obseravtion : swap possible if a_i +a_(i+1) is odd
// what does it really mean??
bool solve(){
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    vector<int> odd,even;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]&1) odd.push_back(a[i]);
        else even.push_back(a[i]);
    }
    vector<int> t1,t2;
    t1=odd;t2=even;
    sort(all(t1));
    sort(all(t2));
    cout<<( (t1==odd && t2==even) ? "YES":"NO" );
 
    return 0;
}
