static bool comp(Item &a, Item &b)
{
    double val_a = (1.0*a.value)/(a.weight);
    double val_b = (1.0*b.value)/(b.weight);
    return val_a<=val_b;
}
class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr, arr+n, comp);
        double capacity = W;
        double profit=0;
        for(int i=n-1; i>-1 && capacity>0; i--)
        {
            if(capacity>arr[i].weight)
            {
                capacity -= arr[i].weight;
                profit += arr[i].value;
            }
            else
            {
                profit += (capacity/arr[i].weight)*(arr[i].value);
                capacity = 0;
            }
        }
        return profit;
    }
        
};
