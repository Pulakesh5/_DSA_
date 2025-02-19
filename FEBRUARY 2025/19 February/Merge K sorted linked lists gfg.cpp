class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        // Your code here
        int k = arr.size(), flag = 1, pos = -1, min;
        Node *mergedList = nullptr, *tmp;
        while(flag)
        {
            pos = -1;
            min = 1001;
            for(int i=0; i<k; i++)
            {
                if(arr[i] == nullptr)
                    continue;
                if(arr[i]->data < min)
                {
                    min = arr[i]->data;
                    pos = i;
                }
            }
            if(pos == -1)
                break;

            if(mergedList == nullptr)
                mergedList = arr[pos];
            else
                tmp->next = arr[pos];

            tmp = arr[pos];
            arr[pos] = arr[pos]->next;
        }
        return mergedList;
        
    }
};
