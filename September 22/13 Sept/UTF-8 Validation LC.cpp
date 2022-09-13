class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int n=data.size();
        for(int i=0;i<n;i++)
        {
            //cout<<i<<" "<<(data[i]&(1<<7))<<endl;
            if(!(data[i]&(1<<7)))
                continue;
            else
            {
                int rpos=7;
                while(rpos>=0 && (data[i]&(1<<rpos)))
                    rpos--;
                int count = (7-rpos);
                //cout<<count<<endl;
                if(count!=1 && count<=4)
                {
                    if((i+count)<=n)
                    {
                        for(int j=1;j<=(count-1);j++)
                        {
                            if(!(data[i+j]&(1<<7)) || (data[i+j]&(1<<6)))
                                return false;
                            //cout<<data[i+j]<<" ";
                        }
                        i+=(count-1);
                    }
                    else
                        return false;
                }
                else
                    return false;
            }
        }
        return true;
    }
};
