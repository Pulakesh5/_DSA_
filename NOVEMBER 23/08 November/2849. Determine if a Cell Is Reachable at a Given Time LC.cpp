class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int d1 = abs(sx-fx), d2 = abs(sy - fy);
        int chDistance = max(d1, d2);
        if((sx==fx && sy==fy && t==1))
            return false;
        cout<<chDistance<<endl;
        return t>=chDistance;
    }
};
