class Solution {
    struct Node* reverse1(struct Node *head){
      Node *temp=NULL;
        while(head!=NULL)
        {
            Node *temp1=head->next;
            head->next=temp;
            temp=head;
            head=temp1;
        }
        return temp;
    }
public:
    struct Node* addTwoLists(struct Node* n1, struct Node* n2)
    {
        // code here
        Node *num1=reverse1(n1);
        Node *num2=reverse1(n2);
        int carry=0;
        vector<int>v;
        while(num1!=NULL || num2!=NULL || carry!=0){
          int x = carry;
          if(num1 != NULL){
              x += num1->data;
              num1 = num1->next;
          }
          if(num2 != NULL){
              x += num2->data;
              num2 = num2->next;
          }
          carry = x / 10;
          x = x % 10;
          v.push_back(x);
        }
        
        int i = v.size() - 1;
        while (i >= 0 && v[i] == 0) {
            i--;
        }

        bool isZero = true;
        for (int j = 0; j < v.size(); ++j) {
            if (v[j] != 0) {
                isZero = false;
                break;
            }
        }

        if (isZero) {
            cout << "0";
        } else {
            while (i >= 0) {
                cout << v[i] << " ";
                i--;
            }
        }
        
        return NULL;
    }
};
