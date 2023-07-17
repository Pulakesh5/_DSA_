class Solution {
	public:
	    int find(vector<int> &pos)
	    {
	        int index = INT_MAX;
	        for(int i=0; i<26; i++)
	        {
	            if(pos[i]<0) continue;
	            if(pos[i]>=0)
	                index = min(index, pos[i]);
	        }
	        return index;
	    }
		string FirstNonRepeating(string A){
		    // Code here
		    
		    vector<int> pos(26,-1);
		    string answer;
		    
		    int len = A.size(), index;
		    answer.push_back(A[0]);
		    pos[A[0]-'a'] = 0;
		    
		    for(int i=1; i<len; i++)
            {
                if(pos[A[i]-'a'] == -1)
                    pos[A[i]-'a'] = i;
                else
                    pos[A[i]-'a'] = -2;
                index = find(pos);
                answer.push_back((index == INT_MAX ? '#' : A[index]));
            }
            return answer;
		}
};
