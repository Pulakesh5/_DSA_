class Solution{
    public:
    long long countPairs(int N, int X, vector<int> numbers){
        long long ans=0;
        
        map<string,int> freq;
        for(int i=0;i<N;i++){
            freq[to_string(numbers[i])]++;
        }
        string original=to_string(X);
        int n=original.length();
        for(int i=1;i<n;i++){
            string s1=original.substr(0,i);
            string s2=original.substr(i);
            
            if(s1!=s2){
                if(freq.count(s1) && freq.count(s2))
                    ans+= (freq[s1] * freq[s2]);
            }
            else
                ans += freq[s1]*(freq[s1]-1);
        }
        return ans;
    }
}; 
