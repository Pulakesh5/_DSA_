class Solution {
public:
    int mod =1e9+7;
    int countVowelPermutation(int n) {
        if(n==0) return 0;
        map<char,long long> mp;
        mp['a']=1;
        mp['e']=1;
        mp['i']=1;
        mp['o']=1;
        mp['u']=1;
        // cout<<mp['a']<<" "<<mp['e']<<" "<<mp['i']<<" "<<mp['o']<<" "<<mp['u']<<endl;
        for(int j=2;j<=n;j++){
            
            long long a=mp['a'],e=mp['e'],i=mp['i'],o=mp['o'],u=mp['u'];
            
            mp['a']=(e+i+u)%mod;
            mp['e']=(a+i)%mod;
            mp['i']=(o+e)%mod;
            mp['o']=i;
            mp['u']=(i+o)%mod;
            
            // cout<<mp['a']<<" "<<mp['e']<<" "<<mp['i']<<" "<<mp['o']<<" "<<mp['u']<<endl;
        }
        return (mp['a']+mp['e']+mp['i']+mp['o']+mp['u'])%mod;
        
    }
};
