class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       vector<int> span(n);
       stack<pair<int,int>> sortedList;
       sortedList.push({price[0], 0});
       span[0] = 1;
       for(int i=1; i<n; i++)
       {
            while(!sortedList.empty() && sortedList.top().first <= price[i])
                sortedList.pop();
            if(sortedList.empty())
                span[i] = i+1;
            else {
                span[i] = i - sortedList.top().second;
            }
            sortedList.push({price[i], i});
       }
       return span;
    }
};
