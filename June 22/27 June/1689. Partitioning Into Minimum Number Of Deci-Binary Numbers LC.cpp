class Solution {
public:
    int minPartitions(string str) {
        
        int n=str.length();
        char ch='0'-1;
        for(int i=0;i<n;i++){
            if(str[i]>ch)
                ch=str[i];
        }
        return ch-'0';
    }
};
