class Solution {
    private int predecessor = -1, successor = -1;
    private void traverse(Node root, ArrayList<Node> traversal)
    {
        if(root == null)
            return;
        traverse(root.left, traversal);
        traversal.add(root);
        traverse(root.right, traversal);
    }
    public ArrayList<Node> findPreSuc(Node root, int key) {
        // code here
        ArrayList<Node> traversal = new ArrayList<>();
        traverse(root, traversal);
        ArrayList<Node> list = new ArrayList<>();
        list.add(null);
        list.add(null);
        int N = traversal.size();
        for(int i=0; i<N; i++)
        {
            if(traversal.get(i).data<key)
                list.set(0,traversal.get(i));
                
            if(list.get(1)==null && traversal.get(i).data>key)
                list.set(1, traversal.get(i));
        }
        return list;
    }
}
