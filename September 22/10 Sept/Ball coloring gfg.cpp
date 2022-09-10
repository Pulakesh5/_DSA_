    unsigned long long int noOfWays(unsigned long long int n){
        // code here

            return (2+(n*(n-1)));
        // (n-1C0)=1
        // (n-1C1)=n-1
        // (n-1C2)=(n2-3n+2)/2
        // (n-1C0) + (n-1C1) + (n-1C2) = n+(n2-3n+2)/2=(n2-n+2)=n(n-1)+2;
    }
