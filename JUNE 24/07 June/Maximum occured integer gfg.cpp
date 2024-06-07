class Solution {
  public:
    // l and r are input array
    // maxx : maximum in r[]
    // n: size of array
    // arr[] : declared globally with size equal to maximum in l[] and r[]
    // Function to find the maximum occurred integer in all ranges.
    int maxOccured(int n, int l[], int r[], int maxx) {

        // Your code here
        map<int, int> freq;
        for(int i=0; i<n; i++)
        {
            freq[l[i]]++;
            freq[r[i]+1]--;
        }
        int count=0, maxOccuringElement, maxCount=0;
        for(auto it:freq)
        {
            count += it.second;
            if(count>maxCount)
            {
                maxCount = count;
                maxOccuringElement = it.first;
            }
        }
        return maxOccuringElement;
        
    }
    // 2 3 4 5
    // 1 2 3
    // 3 4 5 6 7 8 9
};
