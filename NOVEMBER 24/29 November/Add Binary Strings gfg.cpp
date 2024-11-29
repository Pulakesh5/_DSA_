class Solution {
  public:
    string addBinary(string& s1, string& s2) {
        // your code here
        size_t len1 = s1.size(), len2 = s2.size();
        int i1 = len1-1, i2 = len2-1;
        short int carry = 0;
        string addedBinary = "";
        while(i1>=0 || i2>=0)
        {
            if(i1>=0)
            {
                // cout<<s1[i1];
                carry += (s1[i1]-'0');
                i1--;
            }
            // cout<<" ";
            if(i2>=0)
            {
                // cout<<s2[i2];
                carry += (s2[i2]-'0');
                i2--;
            }
            
            // cout<<" : "<<carry<<endl;
            addedBinary.push_back('0'+carry%2);
            carry = carry/2;
        }
        if(carry)
            addedBinary.push_back('1');
        // removing leading zeroes
        while(addedBinary.back()=='0')
            addedBinary.pop_back();
        // answering in case of empty string
        if(addedBinary.size()==0)
            return "0";
        reverse(addedBinary.begin(), addedBinary.end());
        return addedBinary;
    }
};
