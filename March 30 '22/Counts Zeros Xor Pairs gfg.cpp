long long int calculate(int a[], int n)
{
    sort(a,a+n);
    long long i=0,j=0,ans=0;
    while(i<n && j<n){
        j=i+1;
        while(j<n && a[i]==a[j]) j++;
        ans+=(j-i)*(j-i-1)/2ll;
        i=j;
    }
    return ans;
}
//
long long int calculate(int a[], int n)
{
    unordered_map<int,long long> mp;
    for(int i=0;i<n;i++)
        mp[a[i]]++;
    long long ans=0;
    for(auto it:mp)
    {
        long long freq=it.second;
        ans+=(freq*(freq-1))/2ll;
    }
    return ans;
}
