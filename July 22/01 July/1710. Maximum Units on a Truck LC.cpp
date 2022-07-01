class Solution {
public:
    static bool comp(vector<int> &a,vector<int> &b){
        if(a[1]!=b[1]) return a[1]>b[1];
        return a[0]>b[0];
    }
    int maximumUnits(vector<vector<int>>& boxes, int truckSize) {
        int n=boxes.size();
        sort(boxes.begin(), boxes.end(), comp);
        int capacity=truckSize,quantity,totalUnits=0,index=0;
        while(capacity && index<n){
            quantity=min(capacity,boxes[index][0]);
            totalUnits+=(quantity*boxes[index][1]);
            capacity-=quantity;
            index++;
            //cout<<index<<" "<<quantity<<" "<<totalUnits<<endl;
        }
        //cout<<endl;
        return totalUnits;
    }
};
