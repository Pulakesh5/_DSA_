bool solve(){
    int key;
    cin>>key;
    vector<int> v(3);
    cin>>v[0]>>v[1]>>v[2];
    for(int i=0;i<3 ;i++){
        key=v[key-1];
        if(key==0){
            if(i==2)
            {
                cout<<"YES";
                return 0;
            }
            else
            {
                cout<<"NO";
                return 0;
            }
        }
    }
    
    return 0;
}
