class solution {
  public:
    long long multiplyTwoLists(Node *first, Node *second) {
        // code here
        long long num_first = 0, num_second = 0;
        long long MOD = 1e9+7;
        while(first != nullptr)
        {
            num_first = num_first*10 + first->data;
            first = first->next;
        }
        while(second != nullptr)
        {
            num_second = num_second*10 + second->data;
            second = second->next;
        }
        return (num_first*num_second)%MOD;
        
    }
};
