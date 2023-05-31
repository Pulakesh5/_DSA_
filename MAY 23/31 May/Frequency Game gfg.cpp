    int LargButMinFreq(int arr[], int n) {
        // code here
        map<int,int> freq;
        for(int i=0;i<n;i++) freq[arr[i]]++;
        int minFrequencyElement, minFrequency = INT_MAX; 
        for(auto it:freq)
        {
            if(it.second<=minFrequency)
            {
                minFrequency = it.second;
                minFrequencyElement = it.first;
            }
        }
      
