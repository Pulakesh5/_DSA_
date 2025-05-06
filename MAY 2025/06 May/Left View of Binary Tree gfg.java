class Solution {
    // Function to return list containing elements of left view of binary tree.
    
    ArrayList<Integer> leftView(Node root) {
        // code here
        ArrayList<Integer> list = new ArrayList<>();
        Queue<Node> q = new LinkedList<>();
        if(root != null)
            q.add(root);
        
        while(!q.isEmpty())
        {
            list.add(q.peek().data);
            int n = q.size();
            for(int i=0; i<n; i++)
            {
                Node node = q.poll();
                if(node.left != null)
                    q.add(node.left);
                if(node.right != null)
                    q.add(node.right);
            }
        }
        return list;
    }
}
