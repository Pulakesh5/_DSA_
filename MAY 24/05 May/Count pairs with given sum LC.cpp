class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        // code here
        map<int,int> frequency;
        for(int i=0; i<n; i++)
            frequency[arr[i]]++;
        int num2, pairCount=0;
        for(auto num1:frequency)
        {
            num2 = k-num1.first;
            if(frequency.find(num2)!=frequency.end())
            {
                // cout<<num1.first<<" "<<num2<<endl;
                if(num1.first==num2)
                    pairCount+= ((frequency[num2])*(frequency[num2]-1));
                else
                    pairCount+=(frequency[num1.first]*frequency[num2]);
            }
        }
        pairCount/=2;
        return pairCount;
    }
};
