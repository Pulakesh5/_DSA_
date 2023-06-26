class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        int frontPtr=-1, rearPtr = n;
        int frontSize=0, rearSize=0;
        priority_queue<int,vector<int>,greater<int>> frontQ, rearQ;

        while(frontPtr<n && frontSize<candidates)
        {
            frontSize++;
            frontQ.push(costs[++frontPtr]);
        }
        while(frontPtr<(rearPtr-1) && rearSize<candidates)
        {
            rearSize++;
            rearQ.push(costs[--rearPtr]);
        }
        int frontWorker, rearWorker;
        long long totalHiringCost = 0;
        while(k--)
        {
            if(frontQ.size())
                frontWorker = frontQ.top();
            else
                frontWorker = -1;
            if(rearQ.size())
                rearWorker = rearQ.top();
            else
                rearWorker = -1;
            // cout<<"choosing from ";
            if(frontWorker!=-1 && rearWorker!=-1)
            {
                
                if(frontWorker<=rearWorker)
                {
                    frontQ.pop();
                    totalHiringCost += frontWorker;
                    if(++frontPtr<rearPtr)
                        frontQ.push(costs[frontPtr]);
                    // cout<<"frontQ "<<frontWorker;
                    // cout<<" rearQ "<<rearWorker<<endl;
                }
                else
                {
                    rearQ.pop();
                    totalHiringCost += rearWorker;
                    if(frontPtr<rearPtr-1)
                        rearQ.push(costs[--rearPtr]);
                    // cout<<"frontQ "<<frontWorker;
                    // cout<<"rearQ "<<rearWorker<<endl;
                }
            }
            else
            {
                if(frontWorker!=-1)
                {
                    frontQ.pop();
                    totalHiringCost += frontWorker;
                    if(++frontPtr<rearPtr)
                        frontQ.push(costs[frontPtr]);
                    // cout<<"frontQ "<<frontWorker<<endl;
                }
                else
                {
                    rearQ.pop();
                    totalHiringCost += rearWorker;
                    if(frontPtr<rearPtr-1)
                        rearQ.push(costs[--rearPtr]);
                    // cout<<"rearQ "<<rearWorker<<endl;
                }
            }
        }

        return totalHiringCost;
    }
};
