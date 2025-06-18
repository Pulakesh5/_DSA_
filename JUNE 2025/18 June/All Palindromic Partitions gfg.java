class Solution {
    public ArrayList<ArrayList<String>> palinParts(String s) {
        // code here
        ArrayList<ArrayList<String>> al=new ArrayList<>();
        rec(0,s,al,new ArrayList<>(),new StringBuilder(),0);
        return al;
        
    }
    private void rec(int id,String s,ArrayList<ArrayList<String>> al,ArrayList<String> a,StringBuilder sb,int characters){
        if(id==s.length()){
            if(characters==s.length()) al.add(new ArrayList<>(a));
            return;
        }
        sb.append(s.charAt(id));
        if(palin(sb.toString())){
            a.add(new String(sb.toString()));
            rec(id+1,s,al,a,new StringBuilder(),characters+sb.length());
            a.remove(a.size()-1);
        }
        rec(id+1,s,al,a,sb,characters);
    }
    private boolean palin(String s){
        int l=0,r=s.length()-1;
        while(l<r) if(s.charAt(l++)!=s.charAt(r--)) return false;
        return true;
    }
}
