// class Solution {
//     public List<List<String>> groupAnagrams(String[] strs) {
//         Map<List<Integer>, List<String>> hashMap = new HashMap<>();
        
//         for(String str:strs) {
//             List<Integer> charFreq = new ArrayList<>(Collections.nCopies(26,0));
//             for(char ch:str.toCharArray())
//             {
//                 int index = ch-'a';
//                 charFreq.set(index, charFreq.get(index)+1);
//             }
//             // if this frequency array does not exist, create an empty list
//             List<Integer> key = new ArrayList<>(charFreq);
//             hashMap.putIfAbsent(key, new ArrayList<>());
//             hashMap.get(charFreq).add(str);
//         }

//         // iterate through the whole hashmap and create the list of list of grouped anagrams
//         List<List<String>> groupedAnagrams = new ArrayList<>();
//         for(Map.Entry<List<Integer>, List<String>> iterator:hashMap.entrySet())
//             groupedAnagrams.add(iterator.getValue());
        
//         return groupedAnagrams;
//     }
// }

// Custom hashing function can be used to represent the char frequency, replace the characters with first 26 primes and make their multiplication as the key for hashMap. This seems to be a very good approach especially useful here because strings are smaller in size (<=100)
class Solution{
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> hashMap = new HashMap<>();
        for(String str:strs) {
            char[] charArr = str.toCharArray();
            Arrays.sort(charArr);
            String sorted = new String(charArr);
            hashMap.putIfAbsent(sorted, new ArrayList<String>());
            hashMap.get(sorted).add(str);
        }
        return new ArrayList<>(hashMap.values());
    }
}
