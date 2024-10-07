struct Node *insert(struct Node *head, int data) {
    // Code here
    Node* root = new Node(data);;
    if(head != nullptr) {
        root->npx = XOR(root, head);
    }
    head = root;
    return head;
}

vector<int> getList(struct Node *head) {
    // Code here
    vector<int> list;
    if(head == nullptr)
        return list;
    Node* root = head;
    while(root->npx != nullptr)
    {
        list.push_back(root->data);
        root = XOR(root, root->npx);
    }
    list.push_back(root->data);
    return list;
}
