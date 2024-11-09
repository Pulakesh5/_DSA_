class Solution {
  public:
    string minSum(vector<int> &arr) {
        // code here
        size_t len = arr.size();
        sort(arr.begin(), arr.end());
        int index = arr.size()-1;
        int carry = 0;
        string sum = "";
        int digit = 0;
        for(; index>0; index-=2)
        {
            digit = arr[index]+arr[index-1]+carry;
            carry = digit/10;
            digit = digit%10;
            sum.push_back('0'+digit);
        }
        if(index==0)
        {
            digit = arr[index] + carry;
            sum.push_back('0'+digit%10);
            carry = digit/10;
        }
        if(carry)
            sum.push_back('1');
        // removing trailing zeroes
        while(sum.size() && sum.back()=='0')
            sum.pop_back();
        // zero sum
        if(sum.size()==0)
            return "0";
            
        reverse(sum.begin(), sum.end());
        return sum;
    }
};
