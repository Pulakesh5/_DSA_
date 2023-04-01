    long long int minOperations(int N) {
        // Code here
        long long operation=1ll*(N/2)*(N/2+1);
        if(N&1)
            return operation;
        else
            return (1ll*N*(N+1))/2-operation;
    }
