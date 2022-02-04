// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

//As you guessed it correctly, it is a trie question
class TrieNode{
public:
    int count;
    TrieNode* next[26];
    bool isword;
    TrieNode(bool flag=false){
        count=0;
        memset(next, NULL, sizeof(next));
        isword=flag;
        count=0;
    }
};
class Solution
{
    public:
    TrieNode* root;
    vector<string> ans;
    void search( string word){
        int n=word.length();
        TrieNode *t=root;   
        string str="";
        for(int i=0;i<n;i++){
            if(t->count==1)
                break;
            str+=word[i];
            t=t->next[word[i]-'a'];
        }
        ans.push_back(str);
    }
    void insert( string word){
        TrieNode *t=root;
        int n=word.length();
        for(int i=0;i<n;i++){
            if(t->next[word[i]-'a'] == NULL)
                t->next[word[i]-'a']= new TrieNode();
            
            t->count++;
            t=t->next[word[i]-'a'];
        }
        t->isword=true;
    }
    vector<string> findPrefixes(string arr[], int n)
    {
        root= new TrieNode();
        
        for(int i=0;i<n;i++){
            insert(arr[i]);
        }
        
        for(int i=0;i<n;i++){
            search(arr[i]);
        }
        return ans;
    }
    
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        string arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
            
        Solution ob;
        vector<string> ans = ob.findPrefixes(arr, n);
        
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] <<" ";


        cout << "\n";

    }

    return 0;
}
  // } Driver Code Ends
