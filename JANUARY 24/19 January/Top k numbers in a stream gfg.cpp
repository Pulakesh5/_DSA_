class Solution {
  public:
    
    vector<vector<int>> kTop(vector<int>& arr, int n, int k) {
        // code here
        vector<int> place(k+1 , 0);
        vector<vector<int>> ans;
        unordered_map<int,int> mp;
        for(int i = 0 ; i < n ; i++)
        {
            place[k] = arr[i];
            mp[arr[i]]++;
            
            int ele =find( place.begin() , place.end()-1,arr[i])-place.begin()-1;
            
            for(int j = ele ; j>=0 ;j--)
            {
                if(mp[place[j]] < mp[place[j+1]] || (mp[place[j]] == mp[place[j+1]] && place[j]>place[j+1]))
                    swap(place[j], place[j+1]);
                else   break;
            }
            
            vector<int> temp;
            for(int j= 0 ; j<k && place[j]!=0; j++)
                temp.push_back(place[j]);
                
            ans.push_back(temp);
            
        }
        
        return ans;
    }
};
