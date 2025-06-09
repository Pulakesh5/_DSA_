class Solution {
    private void inorder(Node root,
    ArrayList<Integer> leaf,ArrayList<Integer> non_leaf){
        if(root==null){
            return;
        }
        inorder(root.left,leaf,non_leaf);
        if(root.left==null && root.right==null){
            leaf.add(root.data);
        }
        else{
            non_leaf.add(root.data);
        }
        inorder(root.right,leaf,non_leaf);
    }
    private boolean binarySearch(ArrayList<Integer> arr,int tar){
        int n=arr.size();
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr.get(mid)==tar){
                return true;
            }
            else if(arr.get(mid)>tar){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return false;
    }
    public boolean isDeadEnd(Node root) {
        ArrayList<Integer> non_leaf=new ArrayList<>();
        ArrayList<Integer> leaf=new ArrayList<>();
        inorder(root,leaf,non_leaf);
        if(non_leaf.size()==0){
            //System.out.println("Debug"+"  ");
            return false;
        }
        //System.out.println(leaf+"\n"+non_leaf);
        for(int i=0;i<leaf.size();i++){
            int tar=leaf.get(i);
            if(tar==1 && non_leaf.size()>0 && binarySearch(non_leaf,tar+1)){
                //System.out.println("Debug 1"+"  ");
                return true;
            }
            else if(non_leaf.size()>0 && binarySearch(non_leaf,tar+1) &&
            binarySearch(non_leaf,tar-1)){
                //System.out.println("Debug 2"+"  ");
                return true;
            }
        }
        return false;
    }
}
