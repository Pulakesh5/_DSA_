    vector<vector<int> > stockBuySell(vector<int> Price, int n){
        
        int buydate=-1,selldate=-1;
        int buyPrice=INT_MAX,sellPrice=INT_MIN;
        
        vector<vector<int>> dates;
        
        for(int i=0;i<n;i++)
        {
            if(Price[i]<sellPrice && buyPrice<sellPrice && buydate<selldate)
            {
                dates.push_back({buydate,selldate});
                //cout<<buydate<<" "<<selldate<<endl;
                buyPrice=INT_MAX;
                sellPrice=INT_MIN;
                buydate=-1;
                selldate=-1;
            }
            
            if(buyPrice>Price[i])
            {
                //cout<<"buying at price"<<Price[i]<<endl;
                buyPrice=Price[i];
                sellPrice=Price[i];
                buydate=i;
            }
            if(Price[i]>sellPrice)
            {
                sellPrice=Price[i];
                selldate=i;
            }
        }
        if(buyPrice<sellPrice && buydate<selldate)
        {
            dates.push_back({buydate,selldate});
            //cout<<buydate<<" "<<selldate<<endl;
        }
        
        
        return dates;
    }
