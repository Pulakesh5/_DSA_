class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int len = arr.size();
        vector<int> preXOR(len+1);
        map<int,vector<int>> xor_pos;
        //mp[xor] => positions where prefix XOR is 'xor'
        
        xor_pos[0].push_back(-1);
        int tripletCount = 0;
        for(int i=0; i<len; i++)
        {
            preXOR[i+1] = preXOR[i]^arr[i];
            for(auto prevPos:xor_pos[preXOR[i+1]])
            {
                tripletCount += (i-prevPos-1);
            }
            xor_pos[preXOR[i+1]].push_back(i);
            // cout<<i<<" : "<<preXOR[i+1]<<endl;
        }
        
        return tripletCount;
    }
};
