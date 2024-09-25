class Solution {
  public:
    // Function to check whether the list is palindrome.
    bool isPalindrome(Node *head) {
        // Your code here
        vector<int> nodeValues;
        while(head)
        {
            nodeValues.push_back(head->data);
            head = head->next;
        }
        int l=0, r=nodeValues.size()-1;
        while(l<r)
        {
            if(nodeValues[l]!=nodeValues[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
};
