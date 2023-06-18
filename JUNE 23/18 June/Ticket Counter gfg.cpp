class Solution {
  public:
    int distributeTicket(int N, int K) {
        // code here
        int index = 1, start = 1, end = N, last=1, c=0;
        while(start<=index && index<=end)
        {
            c=0;
            index = start;
            // cout<<"front : ";
            while(c<K && index<=end)
            {
                c++;
                last = index;
                // cout<<index<<" ";
                index++;
            }
            start = index;
            c=0;
            index = end;
            // cout<<"\nend : ";
            while(c<K && start<=index)
            {
                c++;
                // cout<<index<<" ";
                last = index;
                index--;
            }
            end = index;
        //     cout<<endl;
        }
        return last;
    }
};
