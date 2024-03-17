class Solution{
  public:
    // your task is to complete this function

    int countPairs(struct Node* head1, struct Node* head2, int x) {
        // Code here
        vector<int> list1, list2;
        struct Node *ptr1 = head1, *ptr2 = head2;
        while(ptr1)
        {
            list1.push_back(ptr1->data);
            ptr1 = ptr1->next;
        }
        while(ptr2)
        {
            list2.push_back(ptr2->data);
            ptr2 = ptr2->next;
        }
        sort(list1.begin(), list1.end());
        sort(list2.begin(), list2.end());
        int l=0, h=list2.size()-1;
        int countPair=0;
        while(l<list1.size() && h>=0)
        {
            if(list1[l]+list2[h]==x)
            {
                countPair++;
                l++;
                h--;
            }
            else if(list1[l]+list2[h]<x)
                l++;
            else
                h--;
        }
        return countPair;
    }

};
