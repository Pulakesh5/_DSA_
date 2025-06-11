class BPair
{
    int c,r;
    BPair(int c,int r)
    {
        this.c = c;
        this.r = r;
    }
}

class Solution {
    public int findLength(int[] color, int[] radius) {
        // code here
        ArrayDeque<BPair> st = new ArrayDeque<>();
        int n = color.length;
        for(int i=0;i<n;i++)
        {
            if(!st.isEmpty() && st.peek().c==color[i]&&
            st.peek().r==radius[i])
            // while(!st.isEmpty() && st.peek().c == color[i] 
            // && st.peek().r==radius[i])
            // {
                st.pop();
            // }
            else
            st.push(new BPair(color[i],radius[i]));
        }
        return st.size();
    }
}
