class Solution{
  public:
    //Function to check whether the list is palindrome.
    bool isPal(string s)
    {
        int l = 0, r = s.size() - 1;
        while(l<r)
        {
            if(s[l]!=s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
    bool isPalindrome(Node *head)
    {
        //Your code here
        Node* root = head;
        string s;
        while(root)
        {
            s.push_back(root->data+'0');
            root = root->next;
        }
        return isPal(s);
    }
};
