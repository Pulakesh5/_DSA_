Solution Idea:  do you have any first look observation?? 
                go with that, it's ok
                any string of length 1 doesn't contain any pal(l>1)
                strings of len 2 that doesn't contain pal is 01, 10.
                any other string of len n must have pal(l>1)
bool solve(){
    int l;
    cin>>l;
    string s;
    cin>>s;
    
    if(l==1)
        cout<<"YES";
    else if(l==2 && (s=="01" || s=="10"))
        cout<<"YES";
    else
        cout<<"NO";
    
    return 0;
 
}
