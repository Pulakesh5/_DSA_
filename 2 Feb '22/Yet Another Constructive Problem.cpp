//Time Complexity: O(log2(n))
//space Complexity: O(1)

bool solve(){
    int x;
    cin>>x;
    
    bitset<27> bit_a(x),bit_b(x);
    bool flag=false;
    int ld=__builtin_clz(x);
    int i=27;
    while(i>=0){
        if(bit_b[i]==1)
            break;
        i--;
    }
    ld=i+1;
    //cerr<<i<<'\n';
    //cerr<<ld<<" ";
    for(int i=0;i<=ld && !flag;i++){
        if(bit_b[i]==0)
        {
            bit_a[i]=1;
            flag=true;
        }
    } 
    
    if(!flag) bit_a[ld]=1;
    
    int a,b,c=0;
    a=(int)(bit_a.to_ulong());
    b=(int)(bit_b.to_ulong());
    cout<<a<<" "<<b<<" "<<c;
    
     
    
    
    return 0;
}
