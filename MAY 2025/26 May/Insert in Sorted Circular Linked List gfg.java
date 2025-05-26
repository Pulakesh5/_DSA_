class Solution {
    public Node sortedInsert(Node head, int data) {
        // code here
        Node newNode = new Node(data);
        Node ptr = head;
        if(head.data >= data) 
        {
            newNode.next = head;
            while(ptr.next!=head)
                ptr = ptr.next;
            ptr.next = newNode;
            
            return newNode;
        }
        
        while(ptr.next!=head && ptr.next.data<=data)
            ptr = ptr.next;
        
        newNode.next = ptr.next;
        ptr.next = newNode;
        
        return head;
    }
}
