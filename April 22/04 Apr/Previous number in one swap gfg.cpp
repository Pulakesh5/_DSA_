class Solution{ 
public:
    string previousNumber(string s){
        int n = s.length();
       int p = -1, q;
       for(int i = n - 1; i > 0; i--){
           if(s[i-1] > s[i]){
               p = i - 1, q = i;
               for(int j = p; j < n; j++)
                   if(s[j] > s[q] && s[j] < s[p]) q = j;
               break;
           }
       }
       if(p < 0) return "-1";
       if(p == 0 && s[p+1] == '0') return "-1";
       swap(s[p], s[q]);
       return s;
    }
};
