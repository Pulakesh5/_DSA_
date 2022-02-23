/*Link list node
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution
{
    public:
    Node* insertionSort(struct Node* head)
    {
        Node* sorted = new Node(0);
        while(head){
            Node* keep = head->next;
            Node* temp=sorted;
            //temp=temp->next;
            while(temp->next && temp->next->data < head->data){
                temp=temp->next;
            }
            head->next=temp->next;
            temp->next=head;
            head=keep;
        }
        return sorted->next;
    }
    
};
