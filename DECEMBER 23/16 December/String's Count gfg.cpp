long long int countStr(long long int n){
    //complete the function here
    // (a, b, c)
    
    // (n, 0, 0)
    // (n-1, 1, 0)
    // (n-1, 0, 1)
    // (n-2, 1, 1)
    // (n-2, 0, 2)
    // (n-3, 1, 2)
    if(n==1)
        return 3;
    else if(n==2)
        return (1+2+2+2+1);
    else
        return (1ll + n + n + (n*(n-1)) + (n*(n-1))/2 + (n*(n-1)*(n-2))/2);
}
