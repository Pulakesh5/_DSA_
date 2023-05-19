static bool comp(vector<int> &a, vector<int> &b){
        if(a[0]!=b[0]) return a[0]<b[0];
        else return a[1]<b[1];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n=intervals.size();
        sort(intervals.begin(), intervals.end(), comp);
        int start=intervals[0][0],end=intervals[0][1];
        
        for(int i=1;i<n;i++){
            if(intervals[i][0]<=end)
                end=max(end,intervals[i][1]);
            else{
                ans.push_back({start,end});
                start=intervals[i][0];
                end=intervals[i][1];
            }
        }
        ans.push_back({start,end});
        return ans;
    }
    vector<int>kthSmallestNum(int n, vector<vector<int>> &ranges, int q, vector<int>queries){
        //Write your code here
        
        sort(ranges.begin(), ranges.end());
        vector<vector<int>> mergedRange = merge(ranges);
        int len = mergedRange.size();
        long long totalElements = 0;
        vector<int> preCount(len+1), elements(q);
        for(int i=0;i<len;i++) preCount[i+1] = (preCount[i] + mergedRange[i][1] - mergedRange[i][0] + 1);
        
        // for(int i=0;i<len;i++) cout<<preCount[i+1]<<" ";
            // cout<<mergedRange[i][0]<<" "<<mergedRange[i][1]<<endl;
        // cout<<endl;
        
        for(int i=0;i<q;i++)
        {
            int kIndex = queries[i];
            if(preCount[len] < kIndex)
            {
                elements[i] = -1;
                continue;
            }
            int l = 0, r = len - 1, index, mid;
            while(l<=r)
            {
                mid = (l+r)/2;
                if(mid>0 && preCount[mid-1]<=kIndex && preCount[mid]<=kIndex)
                {
                    index = mid;
                    break;
                }
                else if(preCount[mid]>=kIndex)
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            // cout<<index<<" "<<preCount[index]<<" "<<kIndex<<endl;
            if(index>0)
                kIndex = kIndex - preCount[index];
            elements[i] = mergedRange[index][0] + kIndex - 1;
            // cout<<preCount[index]<<" "<<kIndex<<endl;
        }
        
        return elements;
    } 
