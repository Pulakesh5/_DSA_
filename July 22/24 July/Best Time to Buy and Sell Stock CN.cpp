#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.
    
    int n=prices.size(), buyPrice=prices[0], sellingPrice=prices[0],Profit=0;
    for(int i=1;i<n;i++){
        if(prices[i]>sellingPrice) sellingPrice=prices[i];
        else if(prices[i]<buyPrice){
            buyPrice=prices[i];
            sellingPrice=prices[i];
        }
        Profit=max((sellingPrice-buyPrice),Profit);
    }
    return Profit;
}
