class Solution {
public:
    string reverseString(vector<char>& s) {
        string str="";
        int l=0,r=s.size()-1;
        while(l<r){
            swap(s[l],s[r]);
            l++;r--;
        }
        return str;
    }
};
