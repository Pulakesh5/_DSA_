class Solution {
    public ArrayList<Integer> findSpiral(Node root) {
        // code here
        ArrayList<Integer> list = new ArrayList<>();
        Stack<Node> stk1 = new Stack<>(), stk2 = new Stack<>();
        stk1.push(root);
        int level = 0;
        while(!stk1.isEmpty() || !stk2.isEmpty())
        {
            while(!stk1.isEmpty())
            {
                Node node = stk1.pop();
                list.add(node.data);
                if(node.right != null)
                    stk2.push(node.right);
                if(node.left != null)
                    stk2.push(node.left);
            }
            while(!stk2.isEmpty())
            {
                Node node = stk2.pop();
                list.add(node.data);

                if(node.left != null)
                    stk1.push(node.left);
                if(node.right != null)
                    stk1.push(node.right);
            }
        }
        return list;
    }
}
