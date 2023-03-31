        vector <int> lexicographicallyLargest(vector <int> &a,int n)
        {
            // Code here
            vector<int>res(a);
            int l = 0;
            if(res[n - 1]%2){
                res.push_back(2);
            }else{
                res.push_back(1);
            }
            for(int i=1;i<n+1;i++){
                if(res[i]%2 == res[l]%2){
                    continue;
                }else{
                    sort(res.begin()+l, res.begin()+(i), greater<int>());
                    l = i;
                }
            }
            res.pop_back();
            return res;
        }
