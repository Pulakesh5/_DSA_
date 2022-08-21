class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        int ns=size(stamp), nt=size(target);
        int i,j;
        int prevChanged=-1, star, changed=0;
        
        vector<int> positions;
        positions.reserve(nt);
        
        while(prevChanged!=changed && changed!=nt)
        {
            prevChanged=changed;
            for(i=0; i<=(nt-ns); )
            {
                for(j=0,star=0; j<ns; j++)
                {
                    if(target[i+j]=='?')
                        star++;
                    else if(target[i+j] != stamp[j])
                        break;
                }
                
                if(j==ns && star<ns)
                {
                    positions.push_back(i);
                    memset(&target[i],'?',ns);
                    changed+=(ns-star);
                    i+=ns;
                }
                else
                    i++;
            }
        }
        if(changed!=nt) return {};
        
        reverse(positions.begin(), positions.end());
        return positions;
    }
};
