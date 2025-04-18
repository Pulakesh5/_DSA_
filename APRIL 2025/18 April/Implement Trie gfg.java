import java.util.Arrays;
// User function Template for Java
class Trie {
    class TrieNode{
        char ch;
        boolean isWord;
        TrieNode[] next = new TrieNode[26];
        
        public TrieNode(char ch) {
            this.ch = ch;
            Arrays.fill(this.next,null);
            this.isWord = false;
        }
    }
    TrieNode root = new TrieNode('$');
    public Trie() {
        // Implement Trie
    }

    // Insert a word into the Trie
    public void insert(String word) {
        TrieNode node = root;
        int index;
        for(char ch:word.toCharArray())
        {
            index = ch-'a';
            if(node.next[index]==null)
                node.next[index] = new TrieNode((char)('a'+index));
            node = node.next[index];
        }
        node.isWord = true;
    }

    // Search for a word in the Trie
    public boolean search(String word) {
        TrieNode node = root;
        int index;
        for(char ch:word.toCharArray())
        {
            index = ch-'a';
            if(node.next[index]==null)
                return false;
            node = node.next[index];
        }
        return node.isWord;
    }

    // Check if a prefix exists in the Trie
    public boolean isPrefix(String word) {
        TrieNode node = root;
        int index;
        for(char ch:word.toCharArray())
        {
            index = ch-'a';
            if(node.next[index]==null)
                return false;
            node = node.next[index];
        }
        return true;
    }
}
