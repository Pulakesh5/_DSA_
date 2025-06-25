class Solution {
    boolean sameFreq(String s) {
        // code here
        int freq[]=new int[26];
        for(char i:s.toCharArray()){
            freq[i-'a']++;
        }
        HashMap<Integer,Integer> map=new HashMap<>();
        int a=-1,b=-1;
        for(int i=0;i<26;i++){
        if(freq[i]!=0){
            if(map.get(freq[i])!=null)map.put(freq[i],map.get(freq[i])+1);
            else map.put(freq[i],1);
         if(a==-1) a=freq[i];
         else if(b==-1 && a!=freq[i]) b=freq[i];}
        }
        if(map.size()>2) return false;
        if(map.size()<2) return true;
        if(a==-1 || b==-1 || a==1 || b==1) return true;
        if(Math.abs(a-b)==1 && map.get(Math.max(a,b))==1) return true;
        return false;
    
    }
}
