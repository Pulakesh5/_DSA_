class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        map<int,int> count;
        int basket=0, maxFruit=0;
        for(int l=0,r=0;r<n;r++)
        {
            //cout<<r<<" "<<basket<<endl;
            count[fruits[r]]++;
            basket++;
            
            
            if(count.size()<=2)
            {
                maxFruit=max(maxFruit,basket);
                continue;
            }

            while(count.size()>2 && l<r)
            {
                count[fruits[l]]--;
                basket--;
                if(count[fruits[l]]==0)
                    count.erase(fruits[l]);
                l++;
            }
            maxFruit=max(maxFruit,basket);
        }
        return maxFruit;
    }
};
