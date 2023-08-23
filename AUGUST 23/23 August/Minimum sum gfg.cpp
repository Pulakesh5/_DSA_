class Solution{   
public:
    string solve(int arr[], int n) {
        // code here
        sort(arr, arr+n);
        vector<int> a, b;
        for(int i=0; i<n; i+=2)
        {
            a.push_back(arr[i]);
            if((i+1)<n)
                b.push_back(arr[i+1]);
        }
        int carry = 0, sum;
        string sumStr = "";
        int i, j;
        for(i=a.size()-1, j=b.size()-1; i>=0 && j>=0; i--,j--)
        {
            sum = (a[i]+b[j]+carry);
            sumStr.push_back(sum%10+'0');
            carry = sum/10;
        }
        
        if(i>=0)
            sumStr.push_back(a[0]+carry+'0');
        else if(j>=0)
            sumStr.push_back(b[0]+carry+'0');
        else if(i<0 && j<0 && carry)
            sumStr.push_back(carry+'0');
        
        while(sumStr.size() && sumStr.back()=='0')
            sumStr.pop_back();
        
        reverse(sumStr.begin(), sumStr.end());
        
        return (sumStr.size()==0?"0":sumStr);
    }
};
