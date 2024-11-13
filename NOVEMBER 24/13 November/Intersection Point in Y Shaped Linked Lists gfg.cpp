class Solution {
  public:
    // Function to find intersection point in Y shaped Linked Lists.
    int intersectPoint(Node* head1, Node* head2) {
        // Your Code Here
        set<Node*> visitedNodes;
        Node* root1 = head1;
        while(root1)
        {
            visitedNodes.insert(root1);
            root1 = root1->next;
        }
        Node* root2 = head2;
        while(root2)
        {
            if(visitedNodes.find(root2)!=visitedNodes.end())
                return root2->data;
            root2 = root2->next;
        }
        return -1;
    }
};
