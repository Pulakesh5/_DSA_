    int countOfDonuts(vector<int> &rank,long long Time){
        long long donutCount=0, count, val;
        //cout<<Time<<": ";
        for(int i=0;i<rank.size();i++)
        {
            val=(Time*2)/rank[i];
            
            count= ceil(sqrt(val));
            //cout<<val<<" "<<count<<" "; 
            
            // if(count*(count+1)<=val) donutCount+=count;
            // else donutCount+=(count-1);
            while( count && count*(count+1)>val)
                count--;
            donutCount+=count;
            //cout<<donutCount<<" ";
            //cout<<count<<" "<<donutCount<<", ";
        }
        //cout<<endl;
        return donutCount;
    }
    
    int findMinTime(int Donuts, vector<int>& rank, int Chefs){
        //write your code here
        sort(rank.begin(), rank.end());
        long long l=1, h=(1ll*((Donuts*(Donuts+1))/2)*rank[Chefs-1]);
        long long required=0, donutCount;
        
        long long Time=(l+h)/2, minTime=INT_MAX;
        while(l<=h){
            Time=(l+h)/2;
            
            //cout<<"[ "<<l<<", "<<h<<"] "<<Time<<endl;
            donutCount = countOfDonuts(rank,Time);
            //cout<<Time<<" "<<donutCount<<endl;
            if(donutCount>=Donuts)
            {
                minTime=min(minTime,Time);
                h=Time-1;
            }
            else
                l=Time+1;
        }
        return minTime;
    }
