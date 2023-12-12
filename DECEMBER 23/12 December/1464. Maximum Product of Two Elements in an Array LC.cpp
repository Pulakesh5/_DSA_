class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1=INT_MIN, max2=INT_MIN+1;
        for(int num:nums)
        {
            if(num>=max2)
            {
                max1 = max2;
                max2 = num;
            }
            else if(num>max1)
                max1 = num;
            // cout<<num<<" : "<<max1<<" "<<max2<<endl;
        }
        return (max1-1)*(max2-1);
    }
};
