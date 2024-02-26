class Solution{
	public:
	    void backtrack(int index, string &s, string &subSeq, vector<string> &allSubsets)
	    {
	        if(index>=s.size())
	        {
	            if(subSeq.size())
	                allSubsets.push_back(subSeq);
	            return;
	        }
	        
	        subSeq.push_back(s[index]);
	        backtrack(index+1,s,subSeq,allSubsets);
	        subSeq.pop_back();
	        backtrack(index+1,s,subSeq,allSubsets);
	    }
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    int n = s.size();
		    string subSeq = "";
		    vector<string> allSubsets;
            backtrack(0, s, subSeq, allSubsets);
            sort(allSubsets.begin(), allSubsets.end());
            return allSubsets;
		}
};
