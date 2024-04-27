class Solution {
  public:
    // Function to sort the given doubly linked list using Merge Sort.
    struct Node *sortDoubly(struct Node *head) {
        // Your code here
        struct Node* root = head;
        vector<int> data;
        while(root!=nullptr)
        {
            data.push_back(root->data);
            root = root->next;
        }
        sort(data.begin(), data.end());
        root = head;
        int k = 0;
        while(root!=nullptr)
        {
            root->data = data[k++];
            root = root->next;
        }
        return head;
    }
};
