class Solution
{
    public:
    // your task is to complete this function
    vector<int> sort_bs(vector<int> &values)
    {
        int minIndex, n = values.size();
        for(int i=0; i<(n-1); i++)
        {
            minIndex = i;
            for(int j=i+1; j<n; j++)
            {
                if(values[j]<values[minIndex])
                {
                    minIndex = j;
                }
            }
            swap(values[i], values[minIndex]);
        }
        return values;
    }
    void sort(Node **head)
    {
         // Code here
        Node* head_ptr = *head;
        vector<int> values;
        while(head_ptr)
        {
            values.push_back(head_ptr->data);
            head_ptr = head_ptr->next;
        }
        values = sort_bs(values);
        head_ptr = *head;
        int n = values.size();
        for(int i=0; i<n; i++)
        {
            head_ptr->data = values[i];
            head_ptr = head_ptr->next;
        }
    }
};
