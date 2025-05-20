class Solution {
    static Map<Node, Node> parentMap = new HashMap<>();
    private static Node _targetNode;
    private static int _target;
    
    static void findParent(Node root, Node parent)
    {
        if(root==null)
            return;
        if(root.data == _target)
            _targetNode = root;
        parentMap.put(root, parent);
        findParent(root.left, root);
        findParent(root.right, root);
    }
    
    private static int burnTree()
    {
        Queue<Node> q = new LinkedList<>();
        q.offer(_targetNode);
        boolean[] visited = new boolean[100005];
        visited[_targetNode.data] = true;
        int time = -1;
        while(!q.isEmpty())
        {
            int qsize = q.size();
            for(int i=0; i<qsize; i++)
            {
                Node node = q.poll();
                
                // System.out.print(node.data+" ");
                
                Node parent = parentMap.get(node);
                if(parent != null && !visited[parent.data])
                {
                    q.offer(parent);
                    visited[parent.data] = true;
                }
                
                if(node.left != null && !visited[node.left.data])
                {
                    q.offer(node.left);
                    visited[node.left.data] = true;
                }
                if(node.right != null &&  !visited[node.right.data])
                {
                    q.offer(node.right);
                    visited[node.right.data] = true;
                }
            }
            time++;
            // System.out.println(" time "+time);
        }
        return time;
    }
    public static int minTime(Node root, int target) {
        // code here
        _target = target;
        findParent(root, null);
        return burnTree();
    }
}
