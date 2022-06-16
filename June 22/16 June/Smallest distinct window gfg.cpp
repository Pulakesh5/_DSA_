class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here 
        vector<int>freq1(256 , 0) , freq2(256 , 0);
        for(char ch : str)
        freq1[ch - '\0'] = 1;
        int sum = accumulate(freq1.begin() , freq1.end() , 0);
       
        int n = str.length();
        int i = 0 , j = 0 , mini = n , cnt = 0;
        while(j < n){
            int curr = str[j] - '\0';
            freq2[curr]++;
            if(freq2[curr] == 1)
            cnt++;
            while(cnt >= sum){
                mini = min(mini , j - i + 1);
                curr = str[i] - '\0';
                freq2[curr]--;
                if(freq2[curr] == 0)
                cnt--;
                i++;
                
            }
            j++;
        }
        return mini;
    }
};
