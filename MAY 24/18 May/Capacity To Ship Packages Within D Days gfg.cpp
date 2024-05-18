class Solution {
    private:
    int calculateDay(int cap, int weight[], int N)
    {
        int totalWeight=0;
        int day = 0;
        for(int i=0; i<N; i++)
        {
            if(totalWeight+weight[i]>cap)
            {
                day++;
                totalWeight = weight[i];
            }
            else
                totalWeight+=weight[i];
        }
        if(totalWeight)
            day++;
        return day;
    }
    public:
    int leastWeightCapacity(int arr[], int N, int D) {
        // code here
        int low = *max_element(arr, arr+N);
        int high = 0;
        for(int i=0; i<N; i++)
            high += arr[i];
        int minCapacity = high, capacity;
        while(low<=high)
        {
            capacity = (low+high)/2;
            if(calculateDay(capacity, arr, N)<=D)
            {
                high = capacity - 1;
                minCapacity = min(minCapacity, capacity);
            }
            else
                low = capacity+1;
        }
        return minCapacity;
    }
};
