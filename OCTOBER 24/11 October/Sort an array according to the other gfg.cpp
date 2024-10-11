class Solution{
    public:
    // A1[] : the input array-1
    // N : size of the array A1[]
    // A2[] : the input array-2
    // M : size of the array A2[]
    
    //Function to sort an array according to the other array.
    vector<int> sortA1ByA2(vector<int> A1, int N, vector<int> A2, int M) 
    {
        //Your code here
        map<int, int> freq;
        for(int num:A1)
            freq[num]++;
        int k=0;
        for(int num:A2) {
            if(freq.find(num)!=freq.end()) {
                int count = freq[num];
                while(count--)
                    A1[k++] = num;
                freq.erase(freq.find(num));
            }
        }
        for(auto it:freq) {
            int num = it.first, count = it.second;
            while(count--)
                A1[k++] = num;
        }
        return A1;
    } 
};
