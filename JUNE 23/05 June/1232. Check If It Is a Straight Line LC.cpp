class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& positions) {
        double prevSlope = (double)(positions[1][1]-positions[0][1])/(double)(positions[1][0] - positions[0][0]);
        double nextSlope;
        double epsilon = 1e-6;
        int len = positions.size();
        for(int i=1; i<=len; i++)
        {
            if(i==len){
                cout<<"x is same\n";
                return true;
            }
            if(positions[i][0]!=positions[i-1][0])
                break;
        }
        for(int i=2; i<len; i++)
        {
            nextSlope = (double)(positions[i][1]-positions[i-1][1])/(double)(positions[i][0] - positions[i-1][0]);
            // cout<<prevSlope<<" "<<nextSlope<<endl;
            if(abs(nextSlope-prevSlope) <= epsilon)
            {
                prevSlope = nextSlope;
                continue;
            }
            return false;
        }
        return true;
    }
};
