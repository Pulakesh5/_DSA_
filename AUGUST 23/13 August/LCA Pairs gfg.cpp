#define ll long long
class Solution 
{
    public:
	void count(int root, vector<int> &parent, vector<vector<pair<ll,ll>>> &childs, vector<long long> &countChild)
	{
	   
	    int len = childs[root].size();
	    pair<ll, ll> child;
	    for(int i=0; i<len; i++)
	    {
	        child = childs[root][i];
	        
	        count(child.first, parent, childs, countChild);
	        
	        countChild[root]+=countChild[child.first];
	        
	        childs[root][i] = {child.first, countChild[child.first]};
	    }
	    countChild[root]++;
	}
	vector<long long>calcPairs(int N, vector<int> parent)
	{
	    // Code here
	    vector<vector<pair<ll,ll>>> childs(N);
	    vector<ll> countChild(N);
	    
	    for(int i=1; i<N; i++)
	        childs[parent[i]].push_back({i,0ll});
	    count(0, parent, childs, countChild);
	    
	    vector<ll> countOfChild, countLCA(N);
	    long long count, totalChild, len;
	    
	    for(int i=0; i<N; i++)
	    {
	        count = 0;
	        totalChild = 0;
	        for(auto child: childs[i])
	        {
	            countOfChild.push_back(child.second);
	           // totalChild+=child.second;
	        }
	            
	        len = countOfChild.size();
	        for(int j=0; j<len; j++)
	        {
	            for(int k=j+1; k<len; k++)
	                count+= (countOfChild[j]*countOfChild[k]); 
	        }  
	        countOfChild.clear();
	        count+=(countChild[i]);
	        countLCA[i] = count;
	    }
	    
	    return countLCA;
	}
};
