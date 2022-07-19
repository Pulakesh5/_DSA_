#include <bits/stdc++.h> 
long long merge(long long *arr, long long *temp, long long left,long long mid,long long right){
    long long i=left, j=mid,k=left, inv_count=0;
    while(i<=(mid-1) && j<=right){
        if(arr[i]<=arr[j])
            temp[k++]=arr[i++];
        else
        {
             inv_count+=(mid-i);
             temp[k++]=arr[j++];
        }
    }
    while(i<=(mid-1)) temp[k++]=arr[i++];
    while(j<=right) temp[k++]=arr[j++];
    
    for(int i=left;i<=right;i++) arr[i]=temp[i];
    
    return inv_count;
}
long long mergesort(long long *arr, long long *temp,long long left,long long right){
    long long mid,inv_count=0;
    if(left<right){
        mid=(left+right)/2;
        inv_count += mergesort(arr,temp,left,mid);
        inv_count += mergesort(arr,temp,mid+1,right);
        inv_count += merge(arr,temp,left,mid+1,right);
    }
    return inv_count;
}

long long getInversions(long long *arr, int n){
    // Write your code here.
    long long left=0,right=n-1;
    long long temp[n];
    long long ans=mergesort(arr, temp,left,right);
    return ans;
}
