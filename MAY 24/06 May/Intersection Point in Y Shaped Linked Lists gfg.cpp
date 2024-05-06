int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    stack<Node*> stk1, stk2;
    Node *auxHead;
    auxHead = head1;
    while(auxHead!=nullptr)
    {
        stk1.push(auxHead);
        auxHead = auxHead->next;
    }
    auxHead = head2;
    while(auxHead!=nullptr)
    {
        stk2.push(auxHead);
        auxHead = auxHead->next;
    }
    int intersection = -1;
    while(stk1.top()==stk2.top())
    {
        intersection = stk1.top()->data;
        stk1.pop();
        stk2.pop();
    }
    return intersection;
    
}
