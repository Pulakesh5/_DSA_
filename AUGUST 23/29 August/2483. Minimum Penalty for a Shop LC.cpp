class Solution {
public:
    int bestClosingTime(string customers) {
        int totalCustomers = 0, noCustomer = 0, len = customers.size();
        int bestTime=len;
        for(int i=0; i<len; i++)
            totalCustomers+=(customers[i]=='Y');

        int minPenalty = len;
        for(int i=0; i<len; i++)
        {
            if(totalCustomers+noCustomer<minPenalty)
            {
                minPenalty = totalCustomers+noCustomer;
                bestTime = i;
            }
            totalCustomers-=(customers[i]=='Y');
            noCustomer+=(customers[i]=='N');
        }
        if(totalCustomers+noCustomer<minPenalty)
            bestTime = len;
        return bestTime;
    }
};
