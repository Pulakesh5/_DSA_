class Solution {
    public ArrayList<Integer> findGreater(int[] arr) {
        // code here
        Map<Integer,Integer> freq = new HashMap<>();
        for(int num:arr)
            freq.put(num, freq.getOrDefault(num,0)+1);
        Stack<Integer> stk = new Stack<>();
        int N = arr.length;
        ArrayList<Integer> ans = new ArrayList<>();
        for(int i=N-1; i>=0; i--)
        {
            while(stk.size()>0 && freq.get(stk.peek())<=freq.get(arr[i]))
                stk.pop();
            
            if(stk.size()==0)
                ans.add(-1);
            else
                ans.add(stk.peek());
            stk.push(arr[i]);
        }
        Collections.reverse(ans);
        return ans;
    }
}
