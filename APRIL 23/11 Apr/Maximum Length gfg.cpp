    int solve(int a, int b, int c) {
        // code here
        if(a==b && b==c) return a+b+c;
        vector<int> v={a,b,c};
        sort(v.begin(), v.end());

        if((v[2]/2+v[2]%2)>(v[0]+v[1]+1)) return -1;
        return a+b+c;
        
    }
