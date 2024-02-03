
class Solution
{
    public:
        // Should return decimal equivalent modulo 1000000007 of binary linked list 
        long long unsigned int decimalValue(Node *head)
        {
           // Your Code Here
           long long unsigned int binary = 0;
           long long MOD = 1e9+7;
           while(head)
           {
                binary = (binary*2)%MOD;
                if(head->data == 1)
                    binary = (binary+1)%MOD;
                head = head->next;
           }
           return binary;
        }
};
