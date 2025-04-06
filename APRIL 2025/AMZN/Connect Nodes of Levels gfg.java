class Solution {
    // Function to connect nodes at same level.
    public Node connect(Node root) {
        // Your code goes here
        Queue<Node> q = new ArrayDeque<>();
        q.offer(root);
        while(!q.isEmpty()) {
            int size = q.size();
            for(int i=0; i<size; i++)
            {
                Node node = q.poll();
                if(node.left != null)
                    q.offer(node.left);
                if(node.right != null)
                    q.offer(node.right);
                if(i==(size-1))
                    node.nextRight = null;
                else
                    node.nextRight = q.peek();
            }
        }
        return root;
    }
}
