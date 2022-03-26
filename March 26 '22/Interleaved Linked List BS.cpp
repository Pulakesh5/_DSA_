/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */
LLNode* solve(LLNode* l0, LLNode* l1) {
    LLNode *t0=l0,*t1=l1;
    int counter=0;
    LLNode* dummy;
    while(t0 && t1){
        if((counter%2)==0){
            dummy=t0->next;
            t0->next=t1;
            t0=dummy;
        }
        else{
            dummy=t1->next;
            t1->next=t0;
            t1=dummy;
        }
        counter++;
    }
    if(!l0) return l1;
    return l0;
}
