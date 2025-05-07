
class Solution {
    private static void traverse(ArrayList<ArrayList<Integer>> paths, ArrayList<Integer> path, Node root)
    {
        if(root == null)
            return;
        path.add(root.data);  
        
        if(root.left == null && root.right == null)
            paths.add(new ArrayList<>(path));

        
        traverse(paths, path, root.left);
        traverse(paths, path, root.right);
        
        path.remove(path.size()-1);
    }
    
    public static ArrayList<ArrayList<Integer>> Paths(Node root) {
        // code here
        ArrayList<ArrayList<Integer>> paths = new ArrayList<>();
        ArrayList<Integer> path = new ArrayList<>();
        
        traverse(paths, path, root);
        
        return paths;
    }
}
