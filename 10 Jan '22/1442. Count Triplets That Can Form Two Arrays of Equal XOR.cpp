Method 0: Brute force with no Optimization O(n^4)
Method 1: Brute force with prefix XOR optimization O(n^3)
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n=arr.size();
        vector<int> xr(n+1,0);
        for(int i=0;i<n;i++){
            xr[i+1]=xr[i]^arr[i];
        }
        vector<vector<int>> ans;
        for(int i=0;i<(n-1);i++){
            
            for(int j=i+1;j<n;j++){
                
                int a=xr[i]^xr[j];
                
                for(int k=j;k<n;k++){
                    
                    int b=xr[j]^xr[k+1];
                    
                    if(a==b)
                        ans.push_back({i,j,k});
                }
            }
        }
        
        return ans.size();
    }
};
Method 2: Prefix XOR
            /*
                a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1]
                b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]

                Assume a == b, thus
                a ^ a = b ^ a, thus
                0 = b ^ a, thus
                arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1] ^ arr[j] ^ arr[j + 1] ^ ... ^ arr[k] = 0
                prefix[k+1] = prefix[i]
                
                We only need to find out how many pair (i, k) of prefix value are equal.
                So we can calculate the prefix array first,
                then brute force count the pair.

                Because we once we determine the pair (i,k),
                j can be any number that i < j <= k,
                so we need to plus k - i - 1 to the result res
        
            */
class Solution {
public:
    int countTriplets(vector<int>& xr) {
        xr.insert(xr.begin(),0);
        int n=xr.size();
        for(int i=1;i<n;i++)
            xr[i]^=xr[i-1];
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(xr[i]==xr[j]){
                    //cout<<i<<" "<<j<<endl;
                    res+=(j-i-1);
                }
            }
        }
        
        return res;
    }
};
method 3:
        /*
            Prefix XOR, O(N)
            The problem now is, given an array,
            find out the sum of index distance with A[i] = A[j].

            Basicly, for the same value in the array,
            we need to count the frequncy and the total value at the same time.
            
            you have an array : a[0], a[1].... a[n - 1]

            First things first:
            We need to understand small fact, if xor(a[0....i]) has appeared before at index j then it means xor(a[j+1.....i]) = 0
            Another fact, if xor(a[i....j]) = 0 so this subarray will add (j - i - 1) to the answer.

            Now say currently we are at index i and let xor([0...i]) = x.
            Now say x has occurred 3 times previously at indices (i1, i2, i3)
            our answer for i will be = (i - i1 - 1) + (i - i2 - 1) + (i - i3 - 1)
            if you simplify this further you get f * i - (i1 + i2 + i3) - f = (i - 1) * f - (i1 + i2 + i3)
            
            f = no. of times x has occurred previously.
            (i1 + i2 + i3) = sum of all the indices where x has occurred previously


            Time O(N)
            Space O(N)
        */

class Solution {
public:
    int countTriplets(vector<int>& xr) {
        int n=xr.size(), res=0;
        unordered_map<int,int> count={{0,1}},total;
        int prefix=0;
        for(int i=0;i<n;i++){
            prefix^=xr[i];
            res += (count[prefix]++ * (i) - total[prefix]);
            total[prefix]+= i+1;
        }
        
        return res;
    }
};
