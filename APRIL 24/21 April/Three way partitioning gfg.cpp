class Solution{   
public:
    //Function to partition the array around the range such 
    //that array is divided into three parts.
    void threeWayPartition(vector<int>& array,int a, int b)
    {
        // code here 
        int len = array.size();
        if(len==1)
            return;
        if(len==2)
        {
            if(array[0]>a && array[1]<a || array[0]>b && array[1]<b)
                swap(array[0], array[1]);
            return;
        }
        vector<int> proxy;
        for(int i=0; i<len; i++)
        {
            if(array[i]<a)
                proxy.push_back(array[i]);
        }
        for(int i=0; i<len; i++)
        {
            if(array[i]>=a && array[i]<=b)
                proxy.push_back(array[i]);
        }
        for(int i=0; i<len; i++)
        {
            if(array[i]>b)
                proxy.push_back(array[i]);
        }
        
        array = proxy;
        
    }
};
