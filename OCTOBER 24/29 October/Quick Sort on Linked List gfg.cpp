// Solution class with quickSort function
class Solution {
  public:
    struct Node* quickSort(struct Node* head) {
        // code here
        vector<int> vals;
        Node* root = head;
        while(root)
        {
            vals.push_back(root->data);
            root = root->next;
        }
        sort(vals.begin(), vals.end());
        root = head;
        int k=0;
        while(root)
        {
            root->data = vals[k++];
            root = root->next;
        }
        return head;
    }
};
