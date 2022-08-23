bool check(Node* r1, Node*r2){
    if(!r1 && !r2) return true;
    
    if( (!r1 && r2) || (r1 && !r2) ) return false;
    
    if(!check(r1->left, r2->right)) return false;
    
    if(!check(r1->right, r2->left)) return false;

    return true;
}
bool IsFoldable(Node* root)
{
    // Your code goes here
    return check(root,root);
    
}
