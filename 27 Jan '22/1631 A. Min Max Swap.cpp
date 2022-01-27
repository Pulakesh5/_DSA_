//sort numbers at each index in two diff array one with mins ans maxs, take max of both of these and multiply that's the answer.
bool solve(){
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        cin>>b[i];
    for(int i=0;i<n;i++){
        if(a[i]<b[i])
        {
            int temp=a[i];
            a[i]=b[i];
            b[i]=temp;
        }
    }
    int x= *max_element(all(a)), y= *max_element(all(b));
    cout<<x*y;
    
    return 0;
}
